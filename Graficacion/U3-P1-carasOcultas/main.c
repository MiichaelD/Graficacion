#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>


#define maxX 3.0
#define maxY 3.0	

void Inicializa(void)
{
     


  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();  
  gluOrtho2D(-maxX,maxX,-maxY,maxY);
}

void Dibuja(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//glEnable(GL_DEPTH_BUFFER);
glColor3f(1.0,0.0,0.0);

glBegin(GL_TRIANGLES);
glVertex3f(-1.0f,-1.0f,-1.0f);
glVertex3f(1.0f,-1.0f,-1.0f);
glVertex3f(0.0f,1.0f,-1.0f);
glEnd();
glPointSize(6);
glColor3f(0.0,1.0,0.0);
glBegin(GL_POINTS);
glVertex3f(0.0f,0.0f,1.0f);
glVertex3f(2.0f,1.0f,1.0f);
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
  
  glutInit(&argc, argv);         			
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
  glutInitWindowSize(100,80);      
  glutInitWindowPosition(100, 100);  
  glutCreateWindow("Caras Ocultas");  
  Inicializa();

  glutDisplayFunc(Dibuja);     
  glutMainLoop(); 
  
      return 0;	
}
