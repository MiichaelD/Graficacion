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
glBegin(GL_LINE_LOOP);

glColor3f(1.0,0.0,0.0);//Rojo
//glVertex2i(120,60);

glVertex2i(60,60);
//glColor3f(0.0,1.0,0.0);//Verde
glVertex2i(90,90);

//glColor3f(0.0,0.0,1.0);//Azul
glVertex2i(120,60);
//glColor3f(1.0,1.0,1.0);//Blanco
glVertex2i(70,85);
//glColor3f(1.0,1.0,0.0);//Amarillo
glVertex2i(115,80);

glVertex2i(55,65);

glVertex2i(120,70);

glVertex2i(115,80);

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
glutCreateWindow("Line Loop");
Inicializa();
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
