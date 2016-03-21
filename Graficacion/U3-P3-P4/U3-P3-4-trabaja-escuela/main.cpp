#include <GL/glut.h>
#include <stdlib.h>

void display(void)
{
     glClearColor(0.0,0.0,0.0,0.0);//color de fondo: negro
     
     glClear(GL_COLOR_BUFFER_BIT); //BORRAMOS PANTALLA
    
     glMatrixMode(GL_PROJECTION);  //MODO DE PROYECCION
          
     glLoadIdentity();             //cargamos la matrix identidad
     
     //glOrtho(-1.0,1.0, -1.0,1.0, -5.0,1.0);
     gluPerspective(60.0,1.0,1.0,100.0);
     
     glMatrixMode(GL_MODELVIEW);    //MODO DE MODELADO
     
     glBegin(GL_QUADS);      //dibujamos un CUADRADO
       glColor3f(0.0,1.0,1.0);
       glVertex3f(-0.5,0.5,-0.5); //coordenadas del primer vertice(SUPERIOR-IZDA)
       glVertex3f(-0.5,-0.5,0.5);   //coordenadas del 2do vertice(INFERIOR-IZDA)
       glVertex3f(0.5,-0.5,0.5);   //coordenadas del 3er vertice(INFERIOR-DCHA)
       glVertex3f(0.5,0.5,-0.5);   //coordenadas del 3er vertice(SUPERIOR-DCHA)
     glEnd();
     
     glBegin(GL_TRIANGLES);      //dibujamos un TRIANGULO
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(-0.9,-0.7, 0.0);
        glVertex3f(0.9,-0.7, 0.0);
     glEnd();
     
     glFlush();   
}


    main(int argc, char **argv)
{
   glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Unidad 3 Practica 2");
    glutDisplayFunc(display);
     glutMainLoop();     
     return 0;
}  

