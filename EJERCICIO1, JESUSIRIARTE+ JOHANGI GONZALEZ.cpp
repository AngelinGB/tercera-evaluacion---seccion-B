#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;


#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77
#define escape 27


#define ancho 30
#define alto 15


#define salida_x (ancho - 2)
#define salida_y (alto - 2)


void gotoxy(int x, int y) {
    HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
}


void dibujarmuro(int x, int y, int n, char direccion) {
    for (int i = 0; i < n; i++) {
        gotoxy(x, y);
        cout << "#";

        if (direccion == 'h') {
            x++;
        } else if (direccion == 'v') {
            y++;
        }
    }
}


void dibujarlaberinto() {


    dibujarmuro(0, 0, ancho, 'h');
    dibujarmuro(0, alto - 1, ancho, 'h');
    dibujarmuro(0, 1, alto - 2, 'v');
    dibujarmuro(ancho - 1, 1, alto - 2, 'v');


 
    dibujarmuro(5, 5, 15, 'h');


    dibujarmuro(20, 8, 6, 'v');

    gotoxy(salida_x, salida_y);
    cout << "x";
}

bool verificarcolision(int new_x, int new_y) {

    if (new_x <= 0 || new_x >= ancho - 1 || new_y <= 0 || new_y >= alto - 1) {
        return true;
    }


    if (new_y == 5 && new_x >= 5 && new_x <= 19) {
        return true;
    }


  
    if (new_x == 20 && new_y >= 8 && new_y <= 13) {
        return true;
    }

    return false;
}

int main() {

    int x = 1;
    int y = 1;
    char tecla = ' ';

    system("cls");
    dibujarlaberinto();

    while (tecla != escape) {

    
        gotoxy(x, y);
        cout << "o";

        if (kbhit()) {
            tecla = getch();
            if (tecla == 0 || tecla == -32) {
                tecla = getch();

                int next_x = x;
                int next_y = y;


                switch (tecla) {
                    case arriba:    next_y--; break;
                    case abajo:     next_y++; break;
                    case izquierda: next_x--; break;
                    case derecha:   next_x++; break;
                }

                if (!verificarcolision(next_x, next_y)) {

  
                    gotoxy(x, y);
                    cout << " ";



                    x = next_x;
                    y = next_y;
                }


                if (x == salida_x && y == salida_y) {
                    system("cls");
                    gotoxy(8, 7);
  
                    cout << "¡completado! laberinto superado.";
                    getch();
                    tecla = escape;
                }
            }
        }
  ;
    }

    system("cls");
    return 0;
}
