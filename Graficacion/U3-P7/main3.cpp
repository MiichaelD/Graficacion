#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
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


GLfloat merc = 0.0f;
GLfloat venu = 0.0f;
GLfloat eart = 0.0f;
GLfloat mars = 0.0f;
GLfloat jupi = 0.0f;
GLfloat satu = 0.0f;
GLfloat uran = 0.0f;
GLfloat nept = 0.0f;

GLint ancho=800;
GLint alto=600;

int hazperspec=0;
void newPlanet(GLfloat rot, float trans, float co, float lo, float r,float anch); 
void newPlanet(GLfloat rot, float transX,float transY, float transZ, float co, float lo, float r,float anch);

void reshape(int width, int height)
{
     
     glViewport(0, 0, width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     printf("hazperspec = %d\n",hazperspec);
 /*    if(hazperspec)
         gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f);
     else
*/        glOrtho(-6,6,-4.5,4.5,1,10);

        glMatrixMode(GL_MODELVIEW);
        
        ancho=width;
        alto=height;
}

void LoadIdentity(){
     glLoadIdentity();
     glTranslatef(0.0f, 0.0f, -5.0f);
}

void newPlanet(GLfloat rot, float trans, float co, float lo, float r,float anch){
     newPlanet(rot,0.0f,0.0f,trans,co,lo,r,anch);
}

void newPlanet(GLfloat rot, float rotX, float rotZ, float transX, float co, float lo, float r,float anch){
     LoadIdentity();
     if(hazperspec)
         glRotatef(rot, rotX,1.0f,rotZ);
     else
         glRotatef(rot, rotX,0,1.0f);//,rotZ);
     glTranslatef(transX, 0.0f, 0.0f);      
     glColor3f(co,lo,r);
     sphere(anch,Slices,Stack);    
}

void display(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     LoadIdentity();//Sun
     glColor3f(1.0f,1.0f,0);
     sphere(0.5f,36,36);
     //newPlanet(rotacion,rotX,rotZ,transX,color,Ancho);
     newPlanet(merc,.7f,brown,.12f);     
     newPlanet(venu,0.1f,0.0f,1.05f,orange,.13f);
     newPlanet(eart,-0.1,0.0f,1.4f,green,.15f);
     newPlanet(mars,-0.2f,0.0f,1.9f,red,.20f);
     newPlanet(jupi,0.2f,0.0f,2.6f,purple,.32f);
     newPlanet(satu,3.4f,lightGreen,.29f);
     newPlanet(uran,0.1,0.0f,3.9f,blue,.17f);
     newPlanet(nept,-0.05,0.0f,4.3f,white,.14f);
     
     glFlush();
     glutSwapBuffers();
     

  
}


void Init()
{
  glClearColor(0,0,0,0);
  glEnable(GL_DEPTH_TEST);
  ancho = 400;
  alto  = 400;           
     
}
  
   
void idle()
{
  display();
}
           
void keyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
              
    case 'p':
    case 'P':           
         hazperspec=1;
         reshape(ancho,alto);
         break;
     
     case 'o':
     case 'O':
         hazperspec=0;
         reshape(ancho,alto);
         break;
     
      case 27: // escape
           exit(0);
           break;
      
      
      case '1':
          merc += 0.75f;
          break;
      case '2':
            venu += 0.62;
            break;
      case '3':
           eart += 0.50f;
           break;
      case '4':
            mars += 0.47f;
            break;
      case '5':
            jupi += 0.32f;
            break;
      case '6':
            satu += 0.28f;
            break;
      case '7': 
            uran += 0.15f;
            break;
      case '8':
            nept += 0.12f;
            break;
     
}
}

int main(int argc, char** argv)
{
  
  glutInit(&argc, argv);         			
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
  glutInitWindowPosition(150, 0);
  glutInitWindowSize(ancho, alto);  
  glutCreateWindow("Práctica 7: Sistema Solar");  
  Init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutKeyboardFunc(keyboard);
  glutMainLoop(); 
  
      return 0;	
}
     
