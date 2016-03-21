#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void Inicializa(void)
{
     
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  gluOrtho2D(0.0,640.0,0.0,480.0);
  //gluOrtho2D(0.0,160.0,0.0,120.0);
}

void Dibuja(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);
GLfloat angulo;
int i;
glBegin(GL_LINES);
for (i=0;i<360;i+=3){
    angulo=(GLfloat)i*3.1416/180.0f;// convertir de grados a Radianes
    glVertex2f(0.0f,0.0f);
    glVertex2f(cos(angulo),sin(angulo));
}
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
glutCreateWindow("Lines to Circle");
Inicializa();
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
