#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//biblioteca que permite a manipula��o de janelas

static float movey = 25; //para mover o ponto em incrementais (1 em 1)
static float movex = -90;
GLint direcao = 1;   // para saber a dire��o do ponto no eixo y (+ ou -)
static float escopo = 90;
static float controle = 0;

void timerPonto(int passo){                //fun��o timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
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
    glutPostRedisplay();                 //chama a fun��o desenha toda vez que for necess�ria
    glutTimerFunc(10,timerPonto,1);      //precisamos chamar a fun��o timer toda vez, Ele executa essa fun��o timer e entra aqui novamente. At� eu querer sair da fun��o timer (neste caso, n�o queremos sair)
}

void pontoY(){
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,0.8,1);              //adiciona cor
        glVertex2f(movex,movey);       //desenha um ponto na coordenada x, y, onde y vai ser a vari�vel que criamos para deslocar o ponto neste eixo
    glEnd();
}

void fundo(){
    glColor3f(0,0.8,0);
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-40, 40);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-40, -40);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(40, -40);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(40, 40);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void rua(){
    glColor3f(0.0, 0.0, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-40, 25);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-40, 5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(30, 5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(30, 25);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(10, -40);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(10, 25);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(30, 25);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(30, -40);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}


void faixas(){
    glColor3f(1.0, 1.0, 0.0);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-40, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-40, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-35, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-35, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-33, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-33, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-28, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-28, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-26, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-26, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-21, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-21, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-19, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-19, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-14, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-14, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-12, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-12, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-7, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-7, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-5, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-5, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(0, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(0, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(2, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(2, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(7, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(7, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(9, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(9, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(14, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(14, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(16, 15.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(16, 14.5);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, 14.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, 15.5);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, 15);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, 10);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, 10);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, 15);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, 8);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, 3);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, 3);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, 8);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, 1);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, -4);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -4);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, 1);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, -6);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, -11);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -11);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -6);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, -13);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, -18);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -18);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -13);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, -20);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, -25);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -25);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -20);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, -27);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, -32);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -32);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -27);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(20.5, -34);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(20.5, -39);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -39);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(19.5, -34);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
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
    glClear(GL_COLOR_BUFFER_BIT);      //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)

	glMatrixMode(GL_PROJECTION);       //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity();                  //carrega a proje��o
    gluOrtho2D(-100,100,-100,100);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);        // proje��o do tipo modelo
    glLoadIdentity();                  // carrega a identidade de proje��o de model

    glPushMatrix();
    transformacao();
    glPopMatrix();

    glPushMatrix();                    //insere a matriz de transforma��o corrente na pilha
    pontoY();                       //chama a fun��o que desenha o ponto
    glPopMatrix();                     //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente
	glutSwapBuffers();                 //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers de)
}




int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
    (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
	glutCreateWindow("Exemplo Timer");                              //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                                //fun��o de callback - chama a fun��o desenhaObjetos
    glClearColor(1,1,1,0);                                      //informa a cor de fundo da tela (branco)
    glutTimerFunc(10,timerPonto,1);
    glutMainLoop();                                                 //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                       //retorna zero
}
