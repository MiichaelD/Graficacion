#ifdef WIN32
#include <windows.h>
#endif

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

//#include <GL/gl.h>
#include <GL/glut.h>

void Inicializa(void)
{
     
  glClearColor(0.0,0.0,0.0,0.0);
  glLoadIdentity();
  //gluOrtho2D(0.0,640.0,0.0,480.0);
  gluOrtho2D(0.0,160.0,0.0,120.0);
}

void Dibuja(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);

glPointSize(10);
glEnable(GL_POINT_SMOOTH);
glBegin(GL_POINTS);

glVertex2i(80,60);
glColor3f(0.0,0.0,1.0);
glVertex2i(60,60);
glColor3f(1.0,0.0,0.0);
glVertex2i(60,80);
glColor3f(1.0,1.0,0.0);
glVertex2i(80,80);

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
glutCreateWindow("Punto");
Inicializa();
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
