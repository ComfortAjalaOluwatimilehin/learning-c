hfcal.o: hfcal.c 
	gcc -I./includes -fPIC -c hfcal.c -o hfcal.o
dll: hfcal.o
	gcc -shared hfcal.o
elliptical.o: elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical.o
elliptical: elliptical.o
	gcc  elliptical.o -LC:\Users\ajala\practice\c\lib2\libs  -lhfcal  -o elliptical.exe 