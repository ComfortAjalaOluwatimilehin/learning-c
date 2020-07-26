hfcal.o: hfcal.c 
	gcc -I./includes -fpic -c hfcal.c -o hfcal.o
dll: hfcal.o
	gcc -shared hfcal.o -o C:\Users\ajala\practice\c\lib\libs\hfcal.dll
elliptical.o: elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical.o
elliptical: elliptical.o
	gcc  elliptical.o -LC:\Users\ajala\practice\c\lib\libs  -l hfcal  -o elliptical.exe 