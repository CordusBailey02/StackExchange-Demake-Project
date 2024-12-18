#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrorbase.h"

// For later fixing.
// Undo restablishing of conenction everytime


MYSQL *conn;


void mysql_cleanup()
{
    mysql_close(conn); 
}


int mysql_connection_init()
{
    const char *hostname = getenv("SQL_HOSTNAME");
    const char *username = getenv("SQL_USERNAME");
    const char *psw = getenv("SQL_PASSWORD");
    const char *db = getenv("SQL_DB");
    const unsigned int port = 25060;
    const char *unix_socket = NULL;
    const unsigned long client_flag = 0;
    conn = mysql_init(NULL);

    if(conn == NULL)
    {
        fprintf(stderr, "[mysql_connection_init] %s\n", mysql_error(conn));
        return EXIT_FAILURE;
    }

    if(mysql_real_connect(conn, hostname, username, psw, db, port, unix_socket, client_flag) == NULL)
    {
        fprintf(stderr, "[mysql_connection_init] %s\n", mysql_error(conn));
        return EXIT_FAILURE;
    }

    char query[20] = "USE mydb";
    mysql_query(conn, query);

    return EXIT_SUCCESS;
}


char ***mysql_database_query(char *query_name, struct payload **inbound_payloads, char ***results_table, int *return_flag, int *num_fields, int *num_rows)
{
    MYSQL_RES *result;
    char *query = malloc(sizeof(char)*200);

    size_t payload_length = inbound_payloads[0]->member_count;
    bool query_length_check = false;

    // reset return_flag, num_fields, num_rows
    *return_flag = SUCCESS;
    *num_fields = 0;
    *num_rows = 0;

    MYSQL_ROW row;

    printf("[mysql_database_query] Variables set.\n");

    // Extablish a connection to MYSQL for the client thread. Connection stays
	// open as long as the client is connected.
	// mysql_cleanup();
	if(mysql_connection_init())
	{
        fprintf(stderr, "[handle_client] Unable to establish a connection to MYSQL.\n");
	}
	printf("Connection to MYSQL successful.\n");

    // Check the given query name and send a call to MYSQL run the corresponding 
    // stored procedure.
    if(!strcmp(query_name, "get_categories_from_user"))
    {

        int j = snprintf(query, 100, "CALL get_categories_from_user(\'%s\');",
            (char *) inbound_payloads[0]->data);
    }
    else if(!strcmp(query_name, "add_user_category"))
    {
        if(payload_length < 2)
        {
            query_length_check = true;
        }
        else
        {
            int j = snprintf(query, 100, "CALL add_user_category(\'%s\', \'%d\');",
                (char *) inbound_payloads[0]->data,
                atoi(inbound_payloads[1]->data));
        }
    }
    else if(!strcmp(query_name, "get_user_reports"))
    {
        int j = snprintf(query, 100, "CALL add_user_category(\'%s\');",
            (char *) inbound_payloads[0]->data);
    }
    else if(!strcmp(query_name, "add_new_category"))
    {
        int j = snprintf(query, 100, "CALL add_new_category(\'%s\');",
            (char *) inbound_payloads[0]->data);
    }
    else if(!strcmp(query_name, "add_new_user"))
    {
        if(payload_length < 3)
        {
            query_length_check = true;
        }
        else
        {
            int j = snprintf(query, 200, "CALL add_new_user(\'%s\', \'%s\', \'%s\', 0, 0);",
                (char *) inbound_payloads[0]->data,
                (char *) inbound_payloads[1]->data,
                (char *) inbound_payloads[2]->data);
        }
        
    }
    else if(!strcmp(query_name, "get_all_users"))
    {
        int j = snprintf(query, 100, "CALL get_all_users();");
    }
    else if(!strcmp(query_name, "check_user"))
    {
        int j = snprintf(query, 100, "CALL check_user(\'%s\');",
            (char *) inbound_payloads[0]->data);
    }
    else if(!strcmp(query_name, "get_user_sha"))
    {
        int j = snprintf(query, 100, "CALL get_user_sha(\'%s\');",
            (char *) inbound_payloads[0]->data);
    }
    else if(!strcmp(query_name, "create_new_post"))
    {
        query = realloc(query, 8200);
        int j = snprintf(query, 8200, "CALL create_new_post(\'%s\', \'%d\', \'%s\');",
            (char *) inbound_payloads[0]->data,
            (int) inbound_payloads[1]->data,
            (char *) inbound_payloads[2]->data);
    }
    else if(!strcmp(query_name, "get_all_category_posts"))
    {
        query = realloc(query, 8200);
        int j = snprintf(query, 8200, "CALL get_all_category_posts(\'%d\');", 
            (int) inbound_payloads[0]->data);
    }
    else
    {
        printf("[mysql_database_query] No query found...\n");
        *return_flag = INEXISTENT_QUERY;
        return NULL;
    }

    if(query_length_check)
    {
        printf("[mysql_database_query] Inbound payload had an insuffucient amount of data.\n");
        *return_flag = INSUFFICIENT_PARAMETERS;
        return NULL;
    }

    printf("[mysql_database_query] Query: %s\n", query);
    
    if(mysql_query(conn, query))
    {
        printf("[mysql_database_query] Query Failed...\n");
        fprintf(stderr, "[mysql_database_query] Error: %s\n", mysql_error(conn));
        *return_flag = QUERY_ERROR;
        return NULL;
    }
    free(query);

    printf("[mysql_database_query] Query success...\n");

    // Now that the query has successfully completed, gather the results and return each row.

    unsigned int table_index = 0;

    result = mysql_store_result(conn);

    if(!result) 
    {
        printf("[mysql_database_query] No Result...\n");
        mysql_free_result(result);
        mysql_close(conn);
        return NULL;
    }
    *num_rows = mysql_num_rows(result);
    *num_fields = mysql_num_fields(result);
    results_table = realloc(results_table, sizeof(row) * (*num_rows) + 5);
    if(results_table == NULL)
    {
        printf("[mysql_database_query] Could not allocate enough memory.\n");
        return NULL;
    }
    while ((row = mysql_fetch_row(result)) != 0)
    {
        *(results_table + table_index) = row;
        table_index = table_index + 1;
    }
    // mysql_free_result(result);
    mysql_free_result(result);
	mysql_close(conn);
    printf("[mysql_database_query] Result freed and connection closed...\n");
    return results_table;
}
