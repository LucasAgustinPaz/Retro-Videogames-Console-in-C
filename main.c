#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

char nombreArchivo[20]={"archivoUsuarios.dat"};


char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

int dinero= 1200;
int inside=0;
int rejected=0;

typedef struct
{
    int Rejected;
    int Injected;
    int Dinero;

} Puntaje;

typedef struct
{
    char Nombre[30];
    char Email[30];
    int Edad;
    Puntaje ListaP;
} Usuario;

Usuario Usuario1;

typedef struct
{
    char nombre[20];
    int edad;
    long doc;
} persona;

void board () //tateti
{


    system("cls");
    printf("\n\n Tic-Tac-Toe\n");
    printf(" Player 1 (0) -- Player 2 (x)\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");



}

int checkwin() // tateti
{
    if (square[1] == square[2] && square[2] == square[3]) // win
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7]) // win
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
             != '7' && square[8] != '8' && square[9] != '9') // detecta empate

        return 0;
    else
        return  - 1; // continua el juego
}
void setup() //vivorita
{
    gameover = 0;


    x = height / 2;
    y = width / 2;
label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0;
}
void draw() // vivorita
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1
                    || j == 0
                    || j == height - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx
                         && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }


    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}
void input() // vivorita
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic() // vivorita
{
    Sleep (0.01);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }


    if (x < 0 || x > height|| y < 0 || y > width){
        gameover = 1;
    }


    if (x == fruitx && y == fruity)
    {
label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3;

label4:
        fruity = rand() % 20;
        if (fruity == 0)
            goto label4;
        score += 10;
    }
}
Usuario CargarEstruc(Usuario Usuario1) //registrarse
{


    printf ("NickName:  \n");
    fflush(stdin);
    gets(Usuario1.Nombre);
    printf ("Email:  \n");
    fflush(stdin);
    gets(Usuario1.Email);
    printf ("Age:  \n");
    fflush(stdin);
    scanf("%i",&Usuario1.Edad);
    printf("User created succesfully!\n");

    return Usuario1;
}

void CopiarArchivo(char NombreArchivo[]) // registrarse
{

    FILE *Archivo = fopen(NombreArchivo, "ab");

    if (Archivo!= NULL)
    {
        Usuario1=CargarEstruc(Usuario1);
        fwrite(&Usuario1, sizeof(Usuario), 1, Archivo);

        fclose(Archivo);
    }

}

void MostrarUsuario(char NombreArchivo[]) //archivoUsuariod
{
    FILE *Archivo = fopen(NombreArchivo,"rb");

    if (Archivo!= NULL)
    {
        while (fread(&Usuario1,sizeof (Usuario),1, Archivo)>0)
        {
            MostrarUsuarioEs(Usuario1);
        }
        fclose(Archivo);
    }
}
void MostrarUsuarioEs (Usuario Usuario1) // printUsuario
{
    printf("Su NickName:  %s  \n", Usuario1.Nombre);
    printf("Su Email: %s \n", Usuario1.Email);
    printf("Su Edad:  \n");
}

void MostrarPuntaje(Usuario Usuario1, char NombreArchivo[])
{

    FILE *Archivo = fopen(NombreArchivo, "rb");

    if (Archivo!= NULL)

    {
        printf("    //  INJECTED  //  \\  REJECTED  //  \\  DINERO  //  \n");
        while (fwrite(&Usuario1, sizeof(Usuario), 1, Archivo)>0)
        {
            printf(" %s        %i                %i               %i        \n",Usuario1.Nombre, Usuario1.ListaP.Injected, Usuario1.ListaP.Rejected, Usuario1.ListaP.Dinero);
        }
    }



}
int buscarUsuario(char NombreArchivo[])
{
    int flag = 0;
    Usuario usuarioIngreso;

    printf ("Ingrese su NickName:  \n");
    fflush(stdin);
    gets(usuarioIngreso.Nombre);
    printf ("Ingrese su Email:  \n");
    fflush(stdin);
    gets(usuarioIngreso.Email);

    FILE *Archivo = fopen(NombreArchivo,"rb");

    if (Archivo!= NULL)
    {
        while (fread(&Usuario1,sizeof (Usuario),1, Archivo)>0)
        {


            if(strcmp(Usuario1.Nombre, usuarioIngreso.Nombre) == 0 && strcmp(Usuario1.Email, usuarioIngreso.Email) == 0)
            {

                flag=1;
                printf("Su Usuario a sido ingresado con exito!\n");
                break;
            }


        }
        fclose(Archivo);
    }
    else
    {
        flag = 2;
    }


    return flag;

}


void consolemain ();

//-----------------------------------PatovaGame-------------------------------------------------------------------
void mainUI ()
{
    printf(" \033[0;36m");
    printf("------------------------------------------------------------------------------------------------\n");
    printf(" \033[0;37m");

    printf("\nPeople Inside: %d",inside);
    printf(" \033[0;37m");

    printf(" \033[0;31m");
    printf("        People Rejected: %d", rejected);
    printf(" \033[0;37m");

    printf(" \033[0;32m");
    printf("           Income $: %d \n", dinero);
    printf(" \033[0;37m");
    printf("-----------------------------------\n");
    printf("N C    Document!\nI L   o   o   o   o   o\nG U   |/  |   |   |   | \nH B   |   |   |   |   |\nT\n");
    printf("\n-----------------------------------\n");
    printf("\n\n");
    printf(" \033[0;36m");
    printf("------------------------------------------------------------------------------------------------\n");
    printf(" \033[0;37m");
}

void insideUI()
{
    printf("------------------------------------------------------------------------------------------------\n");
    printf("\nPeople Inside: %d        People Rejected: %d           Income $: %d\n", inside, rejected, dinero);
    printf("-----------------------------------\n");
    printf("N C    Next!\nI L   o   o   o   o   o\nG U   |   |/  |   |   | \nH B   |   |   |   |   |\nT\n");
    printf("\n-----------------------------------\n");
    printf("\n\n");
    printf("------------------------------------------------------------------------------------------------\n");
}

void rejectedUI()
{
    printf("------------------------------------------------------------------------------------------------\n");
    printf("\nPeople Inside: %d       People Rejected: %d            Income $: %d\n", inside, rejected, dinero);
    printf("-----------------------------------\n          o\n          |\n          |\n");
    printf("\n");
    printf("N C      Next!   \nI L   o       o   o   o\nG U   |/      |   |   | \nH B   |       |   |   |\nT\n");
    printf("\n-----------------------------------\n");
    printf("\n\n");
    printf("------------------------------------------------------------------------------------------------\n");
}

int mostrarPersona(persona numero1, int pos)
{
    FILE *arch;
    arch = fopen("personas/personas.bin", "rb");


    if(arch!= NULL)
    {
        fseek(arch, sizeof(persona)*(pos-1),SEEK_SET);
        fread(&numero1, sizeof(persona), 1, arch);

        printf("Name: %s\n", numero1.nombre);
        printf("Age: %d years old\n", numero1.edad);
        printf("ID CARD: %ld\n\n", numero1.doc);

        return numero1.edad;
    }

    fclose(arch);
}
void decisionPersona(int numero1, char decision)
{

    if(numero1>=21 && decision=='n')
    {
        rejected++;
        dinero = dinero - 400;
        rejectedUI();
        printf("Error, he is older than 21 years. (-400$)\n");
    }
    else if(numero1>=21 && decision=='y')
    {
        inside++;
        dinero = dinero + 400;
        insideUI();
        printf("Correct, he is older than 21 years. (+400$)\n");

    }
    else if(numero1<21 && decision=='y')
    {
        inside++;
        dinero=dinero-400;
        insideUI();
        printf("Error, he's is less than 21 years old. (-400$)\n");
    }
    else
    {
        rejected++;
        dinero=dinero+400;
        rejectedUI();
        printf("Correct, he's is less than 21 years old. (+400$)\n");
    }


}
//----------------------------------------------------------------------------------------------------------------

int main()
{
    int a, b=3, c=0;

    system("cls");
    printf(" \033[0;34m");
    printf("                                               Game developed by Lucas Paz \n ");
    printf("                                              Retro videogames console in C\n\n");



    printf(" \033[0;31m");

    printf(" \n                                                         Welcome!!!");
    printf(" \n\n \n                                         #############################################\n");
    printf("                                         #                                           #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             1- Sign up                    #\n");
    printf("                                         #                                           #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             2- Log in                     #\n");
    printf("                                         #                                           #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             3- Exit                       #\n");
    printf("                                         #                                           #\n");
    printf("                                         #############################################\n");


    fflush(stdin);
    scanf("%d", &a);

    if(a==1)
    {
        CopiarArchivo(nombreArchivo);
        //MostrarUsuario(nombreArchivo);

        consolemain_games (a);
    }
    if (a == 2)
    {
        int verificar;

        while(verificar !=1)
        {
            verificar = buscarUsuario(nombreArchivo);

            if(verificar == 1)
            {
                system("cls");
                consolemain_games(a);
            }
            if (verificar == 0)
            {
                printf("User not found\n");
                b--;
                printf("%d tries left.\n", b);


                c++;

                if(c == 3)
                {
                    exit(-1);
                }
            }
            if(verificar == 2)
            {
                printf("No users registered\n");
                exit(-1);
            }
        }

    }
    if(a == 3)
    {
        exit (-1);
    }



    return 0;


}



void consolemain_games (int *a) // Seleccion Juego
{
    system("cls");
    int console;
    printf(" \033[0;31m");

    start: printf(" \n                                                       Bienvendo",Usuario1.Nombre,"!!!!");
    printf(" \n\n \n                                         #############################################\n");
    printf("                                         #                                           #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             1-Ta-Te-Ti(2players)          #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             2-PatovaGame                  #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             3-Snake                       #\n");
    printf("                                         #                                           #\n");
    printf("                                         #             4- Salir                      #\n");
    printf("                                         #                                           #\n");
    printf("                                         #############################################\n");
    printf(" \033[1;37m");
    while(console!=1 || console!=2 || console!=3 || console!=4 || console!= 5)
    {
        scanf("%d", &console);

        system("cls");
        switch(console)
        {

        case 1: // Ta Te Ti
        {
            int player = 1, i, choice;

            char mark;
            do
            {
                board();
                player = (player % 2) ? 1 : 2; // define los turnos

                printf("Player %d, choose a square:  ", player);
                scanf("%d", &choice); // seleccion de casillero

                mark = (player == 1) ? 'X' : 'O'; // que marca va para jugador 1 y para jugador 2

                if (choice == 1 && square[1] == '1')
                    square[1] = mark;

                else if (choice == 2 && square[2] == '2')
                    square[2] = mark;

                else if (choice == 3 && square[3] == '3')
                    square[3] = mark;

                else if (choice == 4 && square[4] == '4')
                    square[4] = mark;

                else if (choice == 5 && square[5] == '5')
                    square[5] = mark;

                else if (choice == 6 && square[6] == '6')
                    square[6] = mark;

                else if (choice == 7 && square[7] == '7')
                    square[7] = mark;

                else if (choice == 8 && square[8] == '8')
                    square[8] = mark;

                else if (choice == 9 && square[9] == '9')
                    square[9] = mark;

                else
                {
                    printf("Invalid Move");

                    player--;
                    getch();
                }
                i = checkwin();

                player++;
            }
            while (i ==  - 1);

            board();

            if (i == 1){
                printf("==>\Player %d Wins! ", --player);
            }
            else{
                printf("==>\a Tied game");
            }

            getch();
            consolemain_games(a);

            return 0;
        }
        break;

        case 2: // Patova Game
        {
            persona numero1;
            int numero2;
            char cont ='y';
            int flag=0;
            int i=1;
            int pos=1;
            char decision;
            int static salida = 0;



            while (cont=='y' && dinero>=0 && salida<4)
            {
                mainUI();

                printf("Patovica: Have your identification in hand! Minium age 21 years.\n");
                printf("\n\nID CARD:\n");

                numero2 = mostrarPersona(numero1, pos);


                printf("Can he/she get inside the party? (y/n)\n");
                fflush(stdin);
                scanf("%c", &decision);


                system("cls");


                decisionPersona(numero2, decision);


                pos++;
                salida++;

                if(salida<4){
                printf("Want to keep playing?(y/n)\n");
                fflush(stdin);
                scanf("%c", &cont);
                }


                system("cls");


            }

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                         End                                                    \n");
            printf("                                                  Thanks for Playing                                                    \n");
            printf("                                                   Done by Lucas Paz\n\n                                                    \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            system("pause");
            consolemain_games(a);

            return 0;
        }
        break;

        case 3: // Vivorita
        {

            setup();


            while (!gameover)
            {
                draw();
                input();
                logic();
            }
            if(gameover){
            getch();
            consolemain_games(a);
            }
        }
        break;

        case 4: // salir
        {
            exit(-1);
            break;
        }

        default: // numero inexistente
        {
            printf(" \033[0;31m");
            printf("Numero incorrecto\n");
            printf(" Ingrese otra opcion: \n");
            printf(" \033[1;37m");
        }


        }
    }

}

