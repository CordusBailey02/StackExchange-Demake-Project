gcc -c terrorexchange.c -o terrorexchange.o
ar rcs libterrorexchange.a terrorexchange.o

gcc -c secure_connection.c -o secure_connection.o
ar rcs libsecure_connection.a secure_connection.o

gcc -c terrorexchangegui.c -o terrorexchangegui.o
ar rcs libterrorexchangegui.a terrorexchangegui.o