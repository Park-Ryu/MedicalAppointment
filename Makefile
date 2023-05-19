mymedic : main.c menu.o medic.o
        gcc -o mymedic main.c menu.o medic.o
menu.o : menu.c menu.h
        gcc -c menu.c -o menu.o
medic.o : medic.c medic.h
        gcc -c medic.c -o medic.o
clean:
        rm *.o mymedic
