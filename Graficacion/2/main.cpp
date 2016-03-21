#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
//<<<<<<<<<<<<<<<<<<<<<<<< Dibuja >>>>>>>>>>>>>>>>>
void Dibuja(void)
{
glClear(GL_COLOR_BUFFER_BIT); // limpia la pantalla
glClearColor(0.2,0.2,0.8,0);
glFlush();
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowSize(640,480);
glutInitWindowPosition(100, 150);
glutCreateWindow("MiichaelD");
glutDisplayFunc(Dibuja);
glutMainLoop();
return 0;
}
