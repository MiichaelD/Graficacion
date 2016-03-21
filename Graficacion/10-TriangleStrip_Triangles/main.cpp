#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void Inicializa(void)
{
     
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,160.0,0.0,120.0);
}

void Dibuja(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_TRIANGLE_STRIP);

glColor3f(1.0,1.0,1.0);//Verde
glVertex2i(0,70);
//glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(30,30);
//glColor3f(1.0,0.0,0.0);//Rojo
glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(30,90);
glColor3f(0.0,0.0,0.0);//negro
glVertex2i(90,30);
glColor3f(0.0,1.0,0.0);//Verde
//glColor3f(0.25,0.5,1.0);//azulillo
glVertex2i(99,90);
glColor3f(1.25,0.0,0.15);//verdesillo
glVertex2i(121,70);
/*
glColor3f(1.0,0.0,0.0);//Rojo
glVertex2i(30,90);
//glColor3f(0.0,1.0,0.0);//Verde
glVertex2i(0,70);
//glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(30,30);
glEnd();

glBegin(GL_TRIANGLE_STRIP);
glColor3f(1.0,0.0,1.0);//Azul
//glColor3f(1.0,1.0,0.0);//Rojo
glVertex2i(31,90);
//glColor3f(0.0,1.0,1.0);//Verde
glVertex2i(31,30);
//glColor3f(1.0,0.0,1.0);//Azul
glVertex2i(60,30);
glEnd();

glBegin(GL_TRIANGLE_STRIP);
glColor3f(0.0,0.5,0.5);//Verde
//glColor3f(0.5,0.5,0.0);//Rojo
glVertex2i(68,90);
//glColor3f(0.0,0.5,0.5);//Verde
glVertex2i(32,90);
//glColor3f(0.5,0.0,0.5);//Azul
glVertex2i(61,30);
glEnd();

glBegin(GL_TRIANGLE_STRIP);
glColor3f(0.75,0.25,0.0);//Rojo
glVertex2i(69,90);
//glColor3f(0.0,0.25,0.75);//Verde
glVertex2i(62,30);
//glColor3f(0.25,0.0,0.75);//Azul
glVertex2i(91,70);
/*
glColor3f(1.0,1.0,1.0);//Blanco
glVertex2i(100,70);
glColor3f(1.0,1.0,0.0);//Amarillo
glVertex2i(110,50);
*/
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
glutCreateWindow("Triangle Strip");
Inicializa();
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
