#include <windows.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <vector.h>
#include <stdio.h>
#include <string.h>

//Colors
#define red 1.0f, 0.0f, 0.0f
#define blue 0.0f, 0.0f, 1.0f
#define green 0.0f, 1.0f, 0.0f
#define yellow 1.0f, 1.0f, 0.0f
#define purple 1.0f, 0.0f, 1.0f
#define brown 0.64,0.16f, 0.16f
#define white 1.0f, 1.0f, 1.0f
#define orange 1.0f, .50f, 0.0f
#define greenYellow 0.50f, 1.0f, 0.0f
#define lightGreen 0.5f, 1.0f, 0.50f
#define darkGreen 0.0f, 0.5f, 0.0f

#define Radio     .15
#define Slices    15
#define Stack     100
#define sphere glutWireSphere
#define maxX 6
#define maxY 9


GLint ancho=800;
GLint alto=600;
GLfloat anguloCubox = 0.0f;
int matriz[maxX][maxY];
int x,y,continuar=1,p1,p2;
int keepFalling=0,aux,points=0; 
time_t t1,t2;
vector<int> lista;
char str[85];

void bajar(){
     keepFalling=0;
     for(x=0;x<maxX;x++)
         for(y=(maxY-1);y>0;y--){
            if(matriz[x][y]==0 && matriz[x][y-1]!=0){
                //if(matriz[x][y-1]>10)
                {
                    matriz[x][y]=matriz[x][y-1];
                    matriz[x][y-1]=0;
                    keepFalling++;
                }
            }
            else 
                 if(matriz[x][y-1]>10)
                     matriz[x][y-1]-=10;
         }
     for(x=0;x<maxX;x++)
           if(matriz[x][maxY-1]>10)
              matriz[x][maxY-1]-=10;
}

void switchElements(){
     for(x=0;x<maxX;x++)
         for(y=0;y<maxY;y++){     
              /*if(matriz[x][y]>10 && matriz[x+1][y]>10){
                   aux=matriz[x][y];
                   matriz[x][y]=matriz[x+1][y];
                   matriz[x+1][y]=aux;                   
                   return;
              }*/
              if(matriz[x][y]>10 && x<maxX-1 && y>0 && matriz[x+1][y]>10  && matriz[x][y-1]==0){
                   matriz[x][y-1]=matriz[x+1][y];
                   matriz[x+1][y]=0;                   
                   return;
              }
              if(matriz[x][y]>10 && y>0 && x>0 && matriz[x][y-1]>10 && matriz[x-1][y]==0){
                   matriz[x-1][y]=matriz[x][y-1];
                   matriz[x][y-1]=0;                   
                   return;
              }
              if(matriz[x][y]>10 && y<maxY-1 && x>0 && matriz[x-1][y]>10 && matriz[x][y+1]==0){
                   matriz[x][y+1]=matriz[x+1][y];
                   matriz[x+1][y]=0;                   
                   return;
              }
              if(matriz[x][y]>10 && y<maxY-1 && x<maxX-1 && matriz[x][y+1]>10 && matriz[x+1][y]==0){
                   matriz[x+1][y]=matriz[x][y+1];
                   matriz[x][y+1]=0;
                   return;
              }
              
                                 
         } 
}

int agregLista(int val){
    int i;
    for(i=0;i<lista.size();i++){
       if(lista[i]==val)
           return 0;
    }
    lista.push_back(val);
    return 1;
}


void checar(int color, int indice, int indice2) {
        if ((indice == 0 && indice2 == 0) || indice == -1 || indice == maxX  || indice2 == -1 || indice2 == maxY)
                return;
        
        aux=indice2*maxX+indice;
        if (color == matriz[indice][indice2] && agregLista(aux)) {
                checar(color,indice - 1, indice2);
                checar(color,indice + 1, indice2);
                checar(color,indice, indice2 - 1);
                checar(color,indice, indice2 + 1);
        } else
                return;
}

void checkCombo(){
     for(x=0;x<maxX;x++)
         for(y=(maxY-1);y>0;y--){
              if(matriz[x][y]){
                  lista.clear();
                  checar(matriz[x][y],x,y);
                  if(lista.size()>3){
                       points+=lista.size()-3;
                       for(int i=0;i<lista.size();i++){
                            matriz[lista[i]%maxX][lista[i]/maxX]=0;
                       }
                  }   
              }
         }
}

void timeToBajar(){
     t2=clock();
     if((t2-t1)*2/CLOCKS_PER_SEC >1){
            bajar();
            checkCombo();
            t1=clock();     
     }
}

void mover(int izq){
     if(izq){
         for(x=0;x<maxX;x++)
              for(y=0;y<maxY;y++){
                  if(matriz[x][y]>10 && x>0 && matriz[x-1][y]==0){
                       matriz[x-1][y]=matriz[x][y];
                       matriz[x][y]=0;
                       
                  }
              }
     }else{
           for(x=maxX-1;x>=0;x--)
              for(y=0;y<maxY;y++){
                  if(matriz[x][y]>10 && x<maxX-1 && matriz[x+1][y]==0){
                       matriz[x+1][y]=matriz[x][y];
                       matriz[x][y]=0;
                  }
              }
     }
}


void reshape(int width, int height){
     glViewport(0, 0, width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-60,60,-45,45,-10,100);
     glMatrixMode(GL_MODELVIEW);
     ancho=width;
     alto=height;
}

void LoadIdentity(){
     glLoadIdentity();
     glTranslatef(0.0f, 0.0f, -5.0f);
}

void dibujarTablero(){
     glLoadIdentity();
     glTranslatef(0.0f, 0.0f, -15.0f);
     glBegin(GL_QUADS);
     glColor3f(0.8,0.8,0.8);//gris
     glVertex2i(-30,45);
     glVertex2i(-30,-45);
     glVertex2i(30,-45);
     glVertex2i(30,45);
     glEnd();
}
int transform(int val, int x){
    if(x)
        return val*10-30;
    else
        return (-1*(val*10-45));
}

void dibCuadro(int color,int x, int y,int rotate){
     if(color!=0){
          LoadIdentity();//cuadro
          if(rotate){
             glRotatef(anguloCubox, 1.0f,0.0f,0.0f);
          }
          glBegin(GL_QUADS);
          switch(color){
     case 1:
     case 11:
         glColor3f(red);//rojo
         break;
     case 2:
     case 12:
         glColor3f(blue);//azul
         break;
     
     case 3:
     case 13:
         glColor3f(green);//verde
         break;
               
     case 4:
     case 14:
         glColor3f(yellow);//amarillo
         break;
               
     case 5:
     case 15:
         glColor3f(purple);//morado
         break;
     
     case 6:
     case 16:
         glColor3f(white);//blanco
         break;
     }
     glVertex2i(x,y);
     glVertex2i(x,y-10);
     glVertex2i(x+10,y-10);
     glVertex2i(x+10,y);
     glEnd();
     }
}

void cleanMatriz(){
     for(x=0;x<maxX;x++){
         for(y=0;y<maxY;y++){
             matriz[x][y]=0;
         }
     }     
     points=0;
}

void dibScore(){
     sprintf(str,"%s %d","Score: ",points);
     glColor3f(lightGreen);
     LoadIdentity();//Score
     glTranslatef(35.0f,-20.0f,-5.0f);
     glRotatef(anguloCubox, 1.0f,1.0f,0.0f);
     glScalef(0.02f,0.02f,0.02f);
     for(int i=0;i<strlen(str);i++)
         glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
}

void dibujoCubo(void){
     LoadIdentity();
     glTranslatef(45.0f,20.0f,-7.0f);
     glRotatef(anguloCubox, 1.0f,1.0f,0.0f);
     
     glColor3f(1.0f, 0.0f,0.0f);
     glBegin(GL_QUADS); // CARA FRONTAL
     glVertex3f(-6.0f,-6.0f,6.0f);
     glVertex3f(6.0f,-6.0f,6.0f);
     glVertex3f(6.0f,6.0f,6.0f);
     glVertex3f(-6.0f,6.0f,6.0f);
     
     glColor3f(0.0f, 1.0f,0.0f);// CARA TRASERA
     glVertex3f(6.0f,-6.0f,-6.0f);
     glVertex3f(-6.0f,-6.0f,-6.0f);
     glVertex3f(-6.0f,6.0f,-6.0f);
     glVertex3f(6.0f,6.0f,-6.0f);
     
     glColor3f(0.0f, 0.0f,1.0f);// CARA LATERAL IZDA
     glVertex3f(-6.0f,-6.0f,-6.0f);
     glVertex3f(-6.0f,-6.0f,6.0f);
     glVertex3f(-6.0f,6.0f,6.0f);
     glVertex3f(-6.0f,6.0f,-6.0f);
     
     glColor3f(1.0f, 1.0f,0.0f);// CARA LATERAL DCHA
     glVertex3f(6.0f,-6.0f,6.0f);
     glVertex3f(6.0f,-6.0f,-6.0f);
     glVertex3f(6.0f,6.0f,-6.0f);
     glVertex3f(6.0f,6.0f,6.0f);
     
     glColor3f(1.0f, 1.0f,1.0f);// CARA ARRIBA
     glVertex3f(-6.0f,6.0f,6.0f);
     glVertex3f(6.0f,6.0f,6.0f);
     glVertex3f(6.0f,6.0f,-6.0f);
     glVertex3f(-6.0f,6.0f,-6.0f);
     
     glColor3f(1.0f, 0.0f,1.0f);// CARA ABAJO
     glVertex3f(6.0f,-6.0f,-6.0);
     glVertex3f(6.0f,-6.0f,6.0);
     glVertex3f(-6.0f,-6.0f,6.0);
     glVertex3f(-6.0f,-6.0f,-6.0);
     glEnd();
     
     anguloCubox += 0.2f;
}

void siguientes(){
     
     sprintf(str,"%s","Siguientes: ");
     glColor3f(darkGreen);
     LoadIdentity();//Score
     glTranslatef(-54.0f,18.0f,-5.0f);
     glScalef(0.03f,0.03f,0.03f);
     for(int i=0;i<strlen(str);i++)
         glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
         
    dibCuadro(p1,transform(-2,1),transform(3,0),1); 
    dibCuadro(p2,transform(-2,1),transform(5,0),1); 
}

void display(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     dibujarTablero();
     for(x=0;x<maxX;x++)
         for(y=0;y<maxY;y++)
            dibCuadro(matriz[x][y],transform(x,1),transform(y,0),0);
     dibScore();
     dibujoCubo();
     siguientes();
     glFlush();
     glutSwapBuffers();
     
     if(keepFalling)
          timeToBajar();   
            
     if(keepFalling==0){
          if(matriz[2][0]==0 && matriz[3][0]==0){
              matriz[2][0]=p1;
              matriz[3][0]=p2;
              p1=11+rand() % 6;
              p2=11+rand() % 6;
              keepFalling=1;
          }
          else{
               cleanMatriz();    
          }
          
     }
}

void Init(){
  glClearColor(0,0,0,0);
  glEnable(GL_DEPTH_TEST);
  ancho = 400;
  alto  = 400;
  
  points=0;
  p1=11+rand() % 6;
  p2=11+rand() % 6;
  
  srand ( time(NULL) );      //semilla numeros aleatorios
     matriz[1][3]=11;
     matriz[2][5]=14;
     matriz[2][7]=12;
     matriz[3][4]=13;
     matriz[4][1]=14;
     matriz[0][0]=15;
     matriz[5][8]=16;

     matriz[1][5]=11;
     matriz[2][3]=13;
     matriz[2][2]=16;
     matriz[3][7]=15;
     matriz[4][8]=12;
     matriz[0][4]=14;
     matriz[5][0]=11;
}
  
   
void idle(){
  display();
}
           
void keyboard(unsigned char key, int x, int y){
   switch(key){              
    case 's':
    case 'S':
         bajar();
    break;
     
    case 'a':
    case 'A':
        mover(1);
    break;
    
    case 'd':
    case 'D':
         mover(0);
    break;
    
    case 'w':
    case 'W':
        switchElements();
    break;
     
    case 27: // escape
    continuar=0;
    exit(0);
    break;
    }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);         			
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
  glutInitWindowPosition(150, 0);
  glutInitWindowSize(ancho, alto);  
  glutCreateWindow("Práctica 8: Final Unidad 3 - SemiPuyoPuyo -"); 
  Init();
  t1=clock();
  t2=clock();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutKeyboardFunc(keyboard);
  glutMainLoop(); 
  return 0;	
}
     
