#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>


void ponerMaterial();//Declaracion de la funcion 

void init(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}

GLfloat a1 = 0.25f;
GLfloat a2 = 0.25f;
GLfloat a3 = 0.25f;


GLfloat d1 = 0.4f;
GLfloat d2 = 0.4f;
GLfloat d3 = 0.4f;


GLfloat s1 = 0.774597f;
GLfloat s2 = 0.774597f;
GLfloat s3 = 0.774597f;

//Definicion de Shine
GLfloat sh = 27.8974f;

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}
void display(void)
{
    GLfloat mat_ambient[] = {a1, a2, a3};
    GLfloat mat_diffuse[] = {d1, d2, d3};
    GLfloat mat_specular[] = {s1, s2, s3};
    GLfloat shine[] = {sh};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

// Rotacion de 25 grados en torno al eje x
    glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
    glutSolidTeapot(110.0);
    glFlush();
}

int color;

void keyboard(unsigned char key, int x, int y)
{
    switch (key)

    {
    case 49:
        color = 1;
        ponerMaterial();
        break;

    case 50:
        color = 2 ;
        ponerMaterial();
        break;

    case 51:
        color = 3;
        ponerMaterial();
        break;

    case 52:
        color = 4;
        ponerMaterial();
        break;

    case 53:
        color = 5;
        ponerMaterial();
        break;
    }

    glutPostRedisplay();// actualización de visualización
}

void ponerMaterial()
{
    if (color == 1)
    {
        a1=0.135; a2=0.2225; a3=0.1575; d1=0.54;d2=0.89; d3=0.63; s1=0.316228; s2=0.316228; s3=0.316228; sh=0.1;
        
        
    }
    if (color == 2)
    {
        a1=0.05375; a2=0.05; a3=0.06625; d1=0.18275;  d2=0.17; d3=0.22525;  s1=0.332741; s2=0.328634; s3=0.346435;  sh=0.3;
             
    }
    if (color == 3)
    {
        a1=0.25; a2=0.20725; a3=0.20725; d1=1.0; d2=0.829; d3=0.829; s1=0.296648; s2=0.296648;  s3=0.296648;  sh=0.088;
         
      
    }
    if (color == 4)
    {
        a1=0.1745; a2=0.01175; a3=0.01175; d1=0.61424; d2=0.04136; d3=0.04136; s1=0.727811; s2=0.626959;  s3=0.625969;  sh=0.6;
         
       
    }
    if (color == 5)
    {
        a1=0.1;a2=0.18725; a3=0.01745; d1=0.396; d2=0.74151; d3=0.69102;  s1=0.297254; s2=0.30829;  s3=0.306678; sh=0.1;
        
        
   
       
        
    }

}

int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (700, 500);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tetera_Cambia_Color");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); //Llamado de la funcion que detecta la tecla precionada
    glutMainLoop();
    return 0;
}
