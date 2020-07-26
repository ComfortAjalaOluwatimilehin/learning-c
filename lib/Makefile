hfcal.o: hfcal.c 
	gcc -I./includes -fpic -c hfcal.c -o hfcal.o
dll: hfcal.o
	gcc -shared hfcal.o -o C:\Users\ajala\practice\c\lib\libs\hfcal.dll
elliptical.o: elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical.o
elliptical: elliptical.o
	gcc  elliptical.o -LC:\Users\ajala\practice\c\lib\libs  -l hfcal  -o elliptical.exe 


hfcal_UK.o: hfcal_UK.c 
	gcc -I./includes -fpic -c hfcal_UK.c -o hfcal_UK.o
dll_UK: hfcal_UK.o
	gcc -shared hfcal_UK.o -o C:\Users\ajala\practice\c\lib\libs\hfcal_UK.dll
elliptical_UK.o: elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical_UK.o 
elliptical_UK: elliptical_UK.o
	gcc elliptical_UK.o -LC:\Users\ajala\practice\c\lib\libs -l hfcal_UK -o elliptical_UK.exe