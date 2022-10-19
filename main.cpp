#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//biblioteca que permite a manipulação de janelas

static float movey = 25; //para mover o ponto em incrementais (1 em 1)
static float movex = -90;
GLint direcao = 1;   // para saber a direção do ponto no eixo y (+ ou -)
static float escopo = 90;
static float controle = 0;

void timerPonto(int passo){                //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    if(controle == 0){
        if(movex <= 35){
            movex++;
        }else{
            controle++;
        }
    }else if(controle == 1){
        if(movey >= -90){
            movey--;
        }else{
            controle++;
        }
    }else if(controle == 2){
        if(movex <= 65){
            movex++;
        }else{
            controle++;
        }
    }else if(controle == 3){
        if(movey <= 48){
            movey++;
        }else{
            controle++;
        }
    }else if(controle == 4){
        if(movex >= -90){
            movex--;
        }else{
            controle++;
        }
    }else if(controle == 5){
        if(movey >= 25){
            movey--;
        }else{
            controle = 0;
        }
    }
    glutPostRedisplay();                 //chama a função desenha toda vez que for necessária
    glutTimerFunc(10,timerPonto,1);      //precisamos chamar a função timer toda vez, Ele executa essa função timer e entra aqui novamente. Até eu querer sair da função timer (neste caso, não queremos sair)
}

void pontoY(){
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0,0.8,1);              //adiciona cor
        glVertex2f(movex,movey);       //desenha um ponto na coordenada x, y, onde y vai ser a variável que criamos para deslocar o ponto neste eixo
    glEnd();
}

void fundo(){
    glColor3f(0,0.8,0);
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-40, 40);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-40, -40);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(40, -40);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(40, 40);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
}

void rua(){
    glColor3f(0.0, 0.0, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-40, 25);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-40, 5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(30, 5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(30, 25);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(10, -40);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(10, 25);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(30, 25);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(30, -40);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
}


void faixas(){
    glColor3f(1.0, 1.0, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-40, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-40, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-35, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-35, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-33, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-33, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-28, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-28, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-26, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-26, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-21, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-21, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-19, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-19, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-14, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-14, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-12, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-12, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-7, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-7, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-5, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-5, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(0, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(0, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(2, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(2, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(7, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(7, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(9, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(9, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(14, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(14, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(16, 15.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(16, 14.5);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, 14.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, 15.5);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, 15);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, 10);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, 10);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, 15);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, 8);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, 3);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, 3);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, 8);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, 1);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, -4);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -4);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, 1);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, -6);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, -11);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -11);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -6);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, -13);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, -18);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -18);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -13);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, -20);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, -25);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -25);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -20);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, -27);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, -32);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -32);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -27);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(20.5, -34);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(20.5, -39);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -39);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(19.5, -34);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
}

void transformacao(){
    //glColor3f(1, 0.84, 0);   //adiciona cor
    //glRotatef(rotacao,0,0,1);     // Gira o objeto 35 graus ao redor do eixo z
    glScalef(2.5, 2.5, 2.5);      // aumenta a escala em 2x
    //glTranslatef(moverx, movery, 0); //move o objeto -5 no x e -1 no y

    glColor3f(0.0, 0.81, 0.0);
    fundo();
    rua();
    faixas();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);      //buffer padrão (limpa a tela toda vez que a função é chamada)

	glMatrixMode(GL_PROJECTION);       //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                  //carrega a projeção
    gluOrtho2D(-100,100,-100,100);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);        // projeção do tipo modelo
    glLoadIdentity();                  // carrega a identidade de projeção de model

    glPushMatrix();
    transformacao();
    glPopMatrix();

    glPushMatrix();                    //insere a matriz de transformação corrente na pilha
    pontoY();                       //chama a função que desenha o ponto
    glPopMatrix();                     //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente
	glutSwapBuffers();                 //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers de)
}




int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
    (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
	glutCreateWindow("Exemplo Timer");                              //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                //função de callback - chama a função desenhaObjetos
    glClearColor(1,1,1,0);                                      //informa a cor de fundo da tela (branco)
    glutTimerFunc(10,timerPonto,1);
    glutMainLoop();                                                 //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                       //retorna zero
}
