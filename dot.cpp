#include <iostream>
#include <GL/glut.h>

using std::cout;

GLsizei wh = 250 ; // initial height of window
GLsizei ww = 250 ; // initial width of window

void Displaydot ( void ) {
    glClear ( GL_COLOR_BUFFER_BIT );
    glBegin(GL_POINTS);
    glVertex2i(40,210); //display a point
    glEnd();
    glFlush();
}

void MyInit ( void ) {
    cout << glGetString(GL_VERSION) <<"\n";
    cout << glGetString(GL_VENDOR) <<"\n";
    glClearColor ( 1.0, 1.0, 1.0, 0.0 ); //white background
    glColor3f(0.0f, 1.0f,0.0f); // green drawing colour
    glPointSize(10.0); // 10 pixel dot!
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ( ) ;
    gluOrtho2D ( 0.0, (GLdouble)ww, 0.0, (GLdouble)wh );
}

int main(int argc, char **argv) {
    glutInit ( &argc, argv );
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize ( ww, wh ); // window size
    glutInitWindowPosition ( 180, 90 ); // & position on screen
    glutCreateWindow ( "Display a Dot" );
    MyInit ( );
    glutDisplayFunc ( Displaydot );
    glutMainLoop ( );
}
