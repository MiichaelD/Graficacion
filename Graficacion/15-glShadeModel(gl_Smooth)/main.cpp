#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void Inicializa(void)
{
     
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glShadeModel(GL_SMOOTH);
  gluOrtho2D(0.0,160.0,0.0,120.0);
}

void Dibuja(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_QUAD_STRIP);

glColor3f(0.0,1.0,0.0);//Verde
glVertex2i(50,80);
//glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(100,85);
//glColor3f(1.0,0.0,0.0);//Rojo
glVertex2i(56,70);
glVertex2i(90,65);
glColor3f(1.0,1.0,1.0);//blanco
//glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(55,49);
//glColor3f(0.25,1.0,0.15);//verdesillo
//glColor3f(1.0,0.0,0.0);//Rojo
glVertex2i(92,42);
//glColor3f(0.5,0.1,0.8);//Verde
glColor3f(1.0,0.0,0.52);//Azul
glVertex2i(65,20);
//glColor3f(0.4,0.45,0.52);//Azul
glVertex2i(104,26);

/*Un color por cada  vertice
glColor3f(0.0,1.0,0.0);//Verde
glVertex2i(50,80);
glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(100,85);
glColor3f(1.0,0.0,0.0);//Rojo
glVertex2i(56,70);
glColor3f(1.0,1.0,1.0);//blanco
glVertex2i(90,65);
glColor3f(0.25,0.5,1.0);//azulillo
glVertex2i(55,49);
glColor3f(0.25,1.0,0.15);//verdesillo
glVertex2i(92,42);
glColor3f(0.5,0.1,0.8);//Verde
glVertex2i(65,20);
glColor3f(0.9,0.5,0.10);//Azul
glVertex2i(104,26);
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
glutCreateWindow("GL_SMOOTH");
Inicializa();
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
