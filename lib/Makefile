encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o
checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o
libhfsecurity.a:encrypt.o checksum.o 
	ar -rcs libhfsecurity encrypt.o checksum.o
bankvault:test_code.c libhfsecurity.a 
	gcc test_code.c -I . -L . libhfsecurity.a -o bankvault