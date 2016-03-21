#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define maxX 160.0
#define maxY 120.0	

void Inicializa(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-maxX,maxX,-maxY,maxY);
}

void Dibuja(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     GLfloat centroX,centroY; 
     int i;
     
     
       glBegin(GL_LINES);////////////////////////CADENA DE MOVIMIENTO
       glColor3f(0.0,0.25,0.25);//
       
       centroX=-80,centroY=-75; 
       for (i = 0; i <= 50; i+=2 ) {
	         glVertex2f(centroX,centroY+i);
	         glVertex2f(centroX+maxX,centroY+i);
	      }
       glEnd();



     
     glBegin(GL_LINES);/////////////////////////////////LLANTA IZQIERDA
     glColor3f(0.0,0.0,1.0);
     centroX=-80;
     centroY=-50;
     GLfloat angulo;
     
     for (i=0;i<360;i+=3){
         angulo=(GLfloat)i*3.1416/180.0f;// convertir de grados a Radianes
         glVertex2f(centroX,centroY);
         glVertex2f(centroX+25*cos(angulo),centroY+25*sin(angulo));
     }
     glEnd();


     glBegin(GL_LINE_STRIP);////////////////////////////LLANTA DERECHA - ESPIRAL
     centroX=80.0;
     centroY=-50.0;
    glColor3f(0.0,0.0,1.0);//Azul
	int W=10,N=30;
	GLfloat x2, y2;
	glVertex2f(centroX,centroY);
		
	      for (i = 1; i <= W*N; ++i ) {
	         GLfloat angle = (GLfloat)2*3.14159*i/N;
	         GLfloat radius = (GLfloat)i/N * 5 / (W+3);
	         x2 = ( 7*radius*cos(angle) );
	         y2 = ( 7*radius*sin(angle) );
	         glVertex2f(centroX+x2,centroY+y2);
	      }
       glEnd();
       
       
       
       
       
       glBegin(GL_TRIANGLE_STRIP);////////////////////////CUERPO DEL TANQUE
       glColor3f(0.0,0.65,0.0);//Azul
       glVertex2f(-145,-25);
       glVertex2f(-110,25);
       glVertex2f(-45,-25);
       glVertex2f(0,25);
       glVertex2f(45,-25);
       glVertex2f(110,25);
       glVertex2f(145,-25);
       glEnd();
       
       
       
       

       
       
       glBegin(GL_QUAD_STRIP);////////////////////////CABEZA DEL TANQUE
       glColor3f(0.0,0.75,0.0);
       glVertex2f(-45,25);
       glVertex2f(-35,75);
       glVertex2f(0,25);
       glVertex2f(0,75);       
       glVertex2f(45,25);
       glVertex2f(35,75);
       glEnd();
       
       glBegin(GL_QUADS);////////////////////////////CAÑON 
       glColor3f(0.0,0.70,0.0);       
       glVertex2f(20,60);
       glVertex2f(20,45);
       glVertex2f(120,45);
       glVertex2f(120,60);
       ///////////////////////////////////////////////CAÑON 
       glVertex2f(-145,-25);
       glVertex2f(-145,-40);
       glVertex2f(145,-40);
       glVertex2f(145,-25);
       glEnd();
       
       
       
glFlush();
}


//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowSize(640,480);
glutInitWindowPosition(100, 150);
glutCreateWindow("Final - Tanque de guerra!");
Inicializa();
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
