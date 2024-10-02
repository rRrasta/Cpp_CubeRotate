#include <GLUT/GLUT.h>
#include <iostream>

float angle = 0.0f; // Угол поворота куба
float speed = 0.1f; // Скорость вращения куба


//выполняется рисование куба на экране с использованием функций OpenGL
void display(){
    glClear(GL_COLOR_BUFFER_BIT); //очищает буфер цвета, чтобы подготовить его для новой отрисовки
    //glRotatef(angle, 1, 1, 0);//выполняет поворот объектов на экране на заданный угол angle вокруг оси
    glRotatef(angle, 1.0, 0.0, 0.0); // Вращение камеры вокруг оси x
    glRotatef(angle, 0.0, 1.0, 0.0); // Вращение камеры вокруг оси y
    glRotatef(angle, 0.0, 0.0, 1.0); // Вращение камеры вокруг оси z
    
    
    glBegin(GL_QUADS);//указывает, что будет рисоваться набор четырехугольников (грани куба).
    
    int razmer = 50;
    
    // Front face+
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-razmer, -razmer, razmer);
    glVertex3f(razmer, -razmer, razmer);
    glVertex3f(razmer, razmer, razmer);
    glVertex3f(-razmer, razmer, razmer);
    
    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-razmer, -razmer, -razmer);
    glVertex3f(-razmer, razmer, -razmer);
    glVertex3f(razmer, razmer, -razmer);
    glVertex3f(razmer, -razmer, -razmer);

    
    // Top face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-razmer, razmer, -razmer);
    glVertex3f(-razmer, razmer, razmer);
    glVertex3f(razmer, razmer, razmer);
    glVertex3f(razmer, razmer, -razmer);
    
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-razmer, -razmer, -razmer);
    glVertex3f(razmer, -razmer, -razmer);
    glVertex3f(razmer, -razmer, razmer);
    glVertex3f(-razmer, -razmer, razmer);


    // Right face
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(razmer, -razmer, -razmer);
    glVertex3f(razmer, razmer, -razmer);
    glVertex3f(razmer, razmer, razmer);
    glVertex3f(razmer, -razmer, razmer);

    
    // Left face
    glColor3f(0.5f, 0.5f, 1.0f);
    glVertex3f(-razmer, -razmer, -razmer);
    glVertex3f(-razmer, -razmer, razmer);
    glVertex3f(-razmer, razmer, razmer);
    glVertex3f(-razmer, razmer, -razmer);

    glEnd();// завершает рисование четырехугольников
    
    glutSwapBuffers();//обменивает буферы, чтобы отобразить нарисованный куб на экране.
}


//обновляет и перерисовывавает кадры с определенной задержкой
void timer(int = 0){
    angle += 0.01f*speed;
    glutPostRedisplay();// говорит GLUT, что окно должно быть перерисовано в следующем цикле отображения
    display();
    glutTimerFunc(100, timer, 0);//устанавливает таймер для вызова функции timer() с задержкой 100 миллисекунд.
}


//обрабатывает нажатия клавиш на клавиатуре
void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case '+'://увеличение скорости вращения
            speed += 1.0f;
            std::cout << "Скорость равна: " << speed << std::endl;
            break;
        case '-'://уменьшение скорости вращения
            speed -= 1.0f;
            std::cout << "Скорость равна: " << speed << std::endl;
            break;
        case '0'://обнуление скорости вращения
            speed = 0;
            std::cout << "Скорость равна: " << speed << std::endl;
            break;
        default:
            break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(200, 200);
    glutInitWindowPosition(20, 810);
    glutCreateWindow("Cube");
    
    glClearColor(0, 0, 0, 1.0);//устанавливает цвет очистки экрана на черный
    
    glMatrixMode(GL_PROJECTION);//переключает режим матрицы на проекционную
    
    glLoadIdentity();//загружает единичную матрицу в текущую матрицу
    glOrtho(-100, 100, -100, 100, -100, 100);//устанавливает ортографическую проекцию с указанными параметрами
    
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    
    timer();
    glutMainLoop();// запускает основной цикл GLUT, в котором обрабатываются события и вызываются функции обратного вызова
    return 0;
    
}


