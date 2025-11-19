#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;


#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESCAPE 27


#define ANCHO 30 
#define ALTO 15 



#define SALIDA_X (ANCHO - 2) 
#define SALIDA_Y (ALTO - 2) 


void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}


void dibujarMuro(int x, int y, int n, char direccion) {
    for (int i = 0; i < n; i++) {
        gotoxy(x, y);
        cout << "#"; 
        
        if (direccion == 'H' || direccion == 'h') {
            x++;
        } else if (direccion == 'V' || direccion == 'v') {
            y++;
        }
    }
}


void dibujarLaberinto() {

    dibujarMuro(0, 0, ANCHO, 'H');       
    dibujarMuro(0, ALTO - 1, ANCHO, 'H');   
    dibujarMuro(0, 1, ALTO - 2, 'V');     
    dibujarMuro(ANCHO - 1, 1, ALTO - 2, 'V'); 


    

    dibujarMuro(5, 5, 15, 'H'); 
    
 
    dibujarMuro(20, 8, 6, 'V');

    gotoxy(SALIDA_X, SALIDA_Y);
    cout << "X";
}

bool verificarColision(int new_x, int new_y) {
    
  
    if (new_x <= 0 || new_x >= ANCHO - 1 || new_y <= 0 || new_y >= ALTO - 1) {
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
    dibujarLaberinto(); 

    while (tecla != ESCAPE) {
      
        gotoxy(x, y);
        cout << "o";

        if (kbhit()) {
            tecla = getch();
            if (tecla == 0 || tecla == -32) {
                tecla = getch();

                int next_x = x;
                int next_y = y;

        
                switch (tecla) {
                    case ARRIBA:    next_y--; break;
                    case ABAJO:     next_y++; break;
                    case IZQUIERDA: next_x--; break;
                    case DERECHA:   next_x++; break;
                }

                if (!verificarColision(next_x, next_y)) {
                    
                  
                    gotoxy(x, y);
                    cout << " ";

                   
                    x = next_x;
                    y = next_y;
                }

 
                if (x == SALIDA_X && y == SALIDA_Y) {
                    system("cls");
                    gotoxy(8, 7);
                    cout << "¡COMPLETADO! LABERINTO SUPERADO.";
                    getch(); 
                    tecla = ESCAPE; 
                }
            }
        }
        Sleep(10);
    }

    system("cls");
    return 0;
}

