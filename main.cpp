#include <GL/glut.h>
#include <GL/glu.h>
#include <SOIL/SOIL.h>
#include <cmath>
#include <stdio.h>

float anguloTanque = 0.0;
float AngTorreY = 0.0,AngTorreX = 0.0;
int altura[40][40] = {
        {0, 0, 0, 0, 0, 3, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 3, 5, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 5, 6, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 5, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 3, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 4, 0, 0, 3, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 4, 4, 4, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 6, 6, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 7, 7, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 7, 7, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 5, 7, 7, 6, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 5, 5, 6, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 5, 5, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 3, 5, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 5, 6, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 5, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 3, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 4, 0, 0, 3, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 4, 4, 4, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 4, 6, 6, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 7, 7, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 7, 7, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 5, 7, 7, 6, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 5, 5, 6, 6, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 5, 5, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
float posicaoTanqueX = 100.0,posicaoTanqueY = 2.5, posicaoTanqueZ = 100.0; 
GLuint texturaTanque, texturaGrama; 
float anguloCameraX = 0.0, anguloCameraY =0.0;

inline float degreesToRadians(float degrees) {
    return degrees * M_PI / 180.0f;
}

bool teclas[256]; // Array para armazenar o estado das teclas

// Função para carregar uma textura
GLuint carregarTextura(const char* caminho,const char* repeat) {
    GLuint texturaID;
    int largura, altura, canais;
    unsigned char* imagem = SOIL_load_image(caminho, &largura, &altura, &canais, SOIL_LOAD_AUTO);
    
    if (!imagem) {
        printf("Erro ao carregar a imagem: %s\n", SOIL_last_result());
        return 0;
    }

    glGenTextures(1, &texturaID);
    glBindTexture(GL_TEXTURE_2D, texturaID);

    if(repeat == "repetir"){
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Repetição no eixo S
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Repetição no eixo T
    }else{
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // Sem repetição no eixo S
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    }

    // Configura o filtro de textura (opcional, mas recomendado)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    GLenum formato = (canais == 4) ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, formato, largura, altura, 0, formato, GL_UNSIGNED_BYTE, imagem);
    
    SOIL_free_image_data(imagem);
    return texturaID;
}
// Função para desenhar o tanque
void desenharCubo() {
    // Corpo do tanque
    glPushMatrix(); 

    glBegin(GL_QUADS);

    // Face frontal
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5,  0.5);
    glTexCoord2f(2.0, 0.0); glVertex3f( 0.5, -0.5,  0.5);
    glTexCoord2f(2.0, 2.0); glVertex3f( 0.5,  0.5,  0.5);
    glTexCoord2f(0.0, 2.0); glVertex3f(-0.5,  0.5,  0.5);

    // Face traseira
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(2.0, 0.0); glVertex3f( 0.5, -0.5, -0.5);
    glTexCoord2f(2.0, 2.0); glVertex3f( 0.5,  0.5, -0.5);
    glTexCoord2f(0.0, 2.0); glVertex3f(-0.5,  0.5, -0.5);

    // Face esquerda
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(2.0, 0.0); glVertex3f(-0.5, -0.5,  0.5);
    glTexCoord2f(2.0, 2.0); glVertex3f(-0.5,  0.5,  0.5);
    glTexCoord2f(0.0, 2.0); glVertex3f(-0.5,  0.5, -0.5);

    // Face direita
    glTexCoord2f(0.0, 0.0); glVertex3f( 0.5, -0.5, -0.5);
    glTexCoord2f(2.0, 0.0); glVertex3f( 0.5, -0.5,  0.5);
    glTexCoord2f(2.0, 2.0); glVertex3f( 0.5,  0.5,  0.5);
    glTexCoord2f(0.0, 2.0); glVertex3f( 0.5,  0.5, -0.5);

    // Face superior
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5,  0.5, -0.5);
    glTexCoord2f(2.0, 0.0); glVertex3f( 0.5,  0.5, -0.5);
    glTexCoord2f(2.0, 2.0); glVertex3f( 0.5,  0.5,  0.5);
    glTexCoord2f(0.0, 2.0); glVertex3f(-0.5,  0.5,  0.5);

    // Face inferior
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(2.0, 0.0); glVertex3f( 0.5, -0.5, -0.5);
    glTexCoord2f(2.0, 2.0); glVertex3f( 0.5, -0.5,  0.5);
    glTexCoord2f(0.0, 2.0); glVertex3f(-0.5, -0.5,  0.5);

    glEnd();
    glPopMatrix();
}
void desenharSolo(int i, int j) {
    glPushMatrix();

    glBegin(GL_QUADS);
    
    // Face do solo
    glTexCoord2f(0.0, 1.0); glVertex3f(10*i, altura[i][j], 10*j);           // Vértice inferior esquerdo
    glTexCoord2f(1.0, 1.0); glVertex3f(10*i+10, altura[i+1][j], 10*j);      // Vértice inferior direito
    glTexCoord2f(1.0, 0.0); glVertex3f(10*i+10, altura[i+1][j+1], 10*j+10); // Vértice superior direito
    glTexCoord2f(0.0, 0.0); glVertex3f(10*i, altura[i][j+1], 10*j+10);      // Vértice superior esquerdo

    glEnd();

    glPopMatrix();
}
void DesenharRoda() {
    GLUquadricObj* quadric;

    // Cria um objeto de cilindro
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE); // Habilita o mapeamento de textura

    // Configura o material para a roda
    glColor3f(0.0, 0.0, 0.0); // Cor preta para a roda

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); // Ajuste a posição conforme necessário
    glScalef(0.5, 0.5, 0.5); // Ajusta o tamanho da roda (raio e altura)

    // Desenha o cilindro (corpo da roda)
    gluCylinder(quadric, 1.0, 1.0, 0.5, 32, 32);

    // Desenha a face superior da roda
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.5); // Move para a face superior
    gluDisk(quadric, 0.0, 1.0, 32, 1); // Desenha o disco
    glPopMatrix();

    // Desenha a face inferior da roda
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); // Move para a face inferior
    gluDisk(quadric, 0.0, 1.0, 32, 1); // Desenha o disco
    glPopMatrix();

    glPopMatrix();
    gluDeleteQuadric(quadric); // Libere o objeto quadric
}

void desenharCilindro() {
    GLUquadricObj* quadric;

    glPushMatrix();

    // Cria um objeto de cilindro
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE); // Habilita o mapeamento de textura

    // Desenha o cilindro sólido
    gluCylinder(quadric, 0.5, 0.5, 1.0, 32, 32); // Base radius, top radius, height, slices, stacks

    glPopMatrix();
    gluDeleteQuadric(quadric); // Libere o objeto quadric
}
void DesenharCano(){
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.75);
    glScalef(0.4, 0.4, 4.0); 
    desenharCilindro();
    glPopMatrix();
}
void DesenharCanhao(){
    // Torre
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0); 
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.5, 1.5, 1.5);
    desenharCubo();
    glPopMatrix();

    // Canhão
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef(AngTorreX, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, 0.0);
    DesenharCano();
    glPopMatrix();
}
void DesenharEsteiras(){
    //Esteria Esquerda
    glPushMatrix();
    glTranslatef(1.875, -1.0, 0.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glScalef(0.75, 2.0, 5.0);
    desenharCubo();
    glPopMatrix();

    //Esteira Direita
    glPushMatrix();
    glTranslatef(-1.875, -1.0, 0.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glScalef(0.75, 2.0, 5.0);
    desenharCubo();
    glPopMatrix();
}
void DesenharRodas(){
    //Frente Esquerda
    glPushMatrix();
    glTranslatef(2.125,-1.0,1.7);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    DesenharRoda();
    glPopMatrix();
    //Meio Esquerda
    glPushMatrix();
    glTranslatef(2.125,-1.0,0.0);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    DesenharRoda();
    glPopMatrix();
    //Tras Esquerda
    glPushMatrix();
    glTranslatef(2.125,-1.0,-1.7);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    DesenharRoda();
    glPopMatrix();

    //Frente Esquerda
    glPushMatrix();
    glTranslatef(-2.375,-1.0,1.7);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    DesenharRoda();
    glPopMatrix();
    //Meio Esquerda
    glPushMatrix();
    glTranslatef(-2.375,-1.0,0.0);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    DesenharRoda();
    glPopMatrix();
    //Tras Esquerda
    glPushMatrix();
    glTranslatef(-2.375,-1.0,-1.7);
    glRotatef(90.0,0.0,1.0,0.0);
    glScalef(1.5,1.5,1.0);
    DesenharRoda();
    glPopMatrix();
}
void DesenharTanque() {
    // Corpo
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glScalef(3.0, 2.0, 5.0);
    desenharCubo();
    glPopMatrix();

    // Canhão
    glPushMatrix();
    glRotatef(AngTorreY, 0.0, 1.0, 0.0);
    DesenharCanhao();
    glPopMatrix();

    DesenharEsteiras();

    glPushMatrix();
    DesenharRodas();
    glPopMatrix();
}
float calcularAlturaSuavizada(float x, float z) {
    // Converte as coordenadas do tanque para a grade da matriz
    int xBase = static_cast<int>(x) / 10;
    int zBase = static_cast<int>(z) / 10;
    
    // Obter os fatores fracionais de x e z
    float xFrac = (x / 10) - xBase;
    float zFrac = (z / 10) - zBase;

    // Pegar as alturas nos quatro pontos ao redor
    float h00 = altura[xBase][zBase];         // Canto inferior esquerdo
    float h10 = altura[xBase + 1][zBase];     // Canto inferior direito
    float h01 = altura[xBase][zBase + 1];     // Canto superior esquerdo
    float h11 = altura[xBase + 1][zBase + 1]; // Canto superior direito

    // Interpolação bilinear
    float h0 = h00 * (1 - xFrac) + h10 * xFrac; // Interpola na direção X
    float h1 = h01 * (1 - xFrac) + h11 * xFrac; // Interpola na direção X
    return h0 * (1 - zFrac) + h1 * zFrac;       // Interpola na direção Z
}

// Função de exibição
void exibir() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Atualize a posição da câmera para girar ao redor do tanque
    float cameraDistancia = 15.0; // Distância da câmera ao tanque
    // Calcular a posição da câmera com base nos ângulos AngTorreX e AngTorreY
    GLfloat anguloTotal = AngTorreY + anguloTanque;
    posicaoTanqueY=calcularAlturaSuavizada(posicaoTanqueX,posicaoTanqueZ)+2.5;

    GLfloat cameraX = posicaoTanqueX - cameraDistancia* std::sin(degreesToRadians(anguloTotal)) * std::cos(degreesToRadians(AngTorreX));
    GLfloat cameraY = posicaoTanqueY+3.0 + cameraDistancia * std::sin(degreesToRadians(AngTorreX));  // Ajuste a altura da câmera
    GLfloat cameraZ = posicaoTanqueZ - cameraDistancia * std::cos(degreesToRadians(anguloTotal)) * std::cos(degreesToRadians(AngTorreX));

    // A câmera olha na direção em que o canhão está apontando
    GLfloat focoX = posicaoTanqueX;
    GLfloat focoY = posicaoTanqueY+2.0 + std::sin(degreesToRadians(AngTorreX));  // Ponto de foco no canhão
    GLfloat focoZ = posicaoTanqueZ + std::sin(degreesToRadians(AngTorreY)) * std::cos(degreesToRadians(AngTorreX));

    // Definir a câmera usando gluLookAt
    gluLookAt(cameraX, cameraY, cameraZ,   // Posição da câmera
              focoX, focoY, focoZ,         // Ponto de foco
              0.0, 1.0, 0.0);             // Vetor 'up' (cima)
    //Tanque
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaTanque);
    glRotatef(0.0,0.0,0.0,1.0);
    glTranslatef(posicaoTanqueX, posicaoTanqueY, posicaoTanqueZ); 
    glRotatef(anguloTanque, 0.0, 1.0, 0.0); 
    DesenharTanque();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texturaGrama);
    for (int i=0;i<40;i++){
        for (int j=0;j<40;j++){
            desenharSolo(i,j);
        }
    }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glutSwapBuffers();
}

// Função para configurar a iluminação
void configurarIluminacao() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat luzAmbiente[] = { 0.8, 0.8, 0.8, 1.0 }; 
    GLfloat luzDifusa[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat luzSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat posicaoLuz[] = { 10.0, 10.0, 10.0, 1.0 }; 

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    // Configura propriedades do material para garantir visibilidade da textura
    GLfloat ambienteMaterial[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat difusoMaterial[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat especularMaterial[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat brilhoMaterial[] = { 80.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambienteMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difusoMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, brilhoMaterial);

    glShadeModel(GL_SMOOTH); // Sombreamento suave
}

// Função para inicialização
void inicializar() {
    glEnable(GL_DEPTH_TEST);
    configurarIluminacao();
    texturaTanque = carregarTextura("militar.jpeg", "repetir");
    texturaGrama = carregarTextura("grama.jpeg","repetir");
}

// Função para processamento de teclas
void teclado(unsigned char tecla, int x, int y) {
    teclas[tecla] = true;
}

// Função para processamento de teclas soltas
void tecladoSolto(unsigned char tecla, int x, int y) {
    teclas[tecla] = false;
}

// Função para processamento das teclas de seta
void teclasEspeciais(int tecla, int x, int y) {
    const float velocidadeRotacao = 5.0;

    switch (tecla) {
        case GLUT_KEY_UP:
            AngTorreX -= velocidadeRotacao;
            if (AngTorreX < -15.0) AngTorreX = -15.0;
            break;
        case GLUT_KEY_DOWN:
            AngTorreX += velocidadeRotacao;
            if (AngTorreX > 0.0) AngTorreX = 0.0;
            break;
        case GLUT_KEY_LEFT:
            AngTorreY += velocidadeRotacao;
            if (AngTorreY > 135.0) AngTorreY = 135.0;
            break;
        case GLUT_KEY_RIGHT:
            AngTorreY -= velocidadeRotacao;
            if (AngTorreY < -135.0) AngTorreY = -135.0;
            break;
    }
    glutPostRedisplay();
}

// Função para atualização contínua
void atualizar(int valor) {
    float velocidade = 0.5;
    float radiano = anguloTanque * M_PI / 180.0; 
    float dx = velocidade * sin(radiano); 
    float dz = velocidade * cos(radiano); 

    // Movimentação com as teclas 'w' e 's'
    if (teclas['w']) {
        if(posicaoTanqueX>2.5&&posicaoTanqueX<397.5&&posicaoTanqueZ>2.5&&posicaoTanqueZ<397.5){
            posicaoTanqueX += dx;
            posicaoTanqueZ += dz;
        }
        if(posicaoTanqueX<2.5||posicaoTanqueX>397.5||posicaoTanqueZ<2.5||posicaoTanqueZ>397.5){
            posicaoTanqueX -= dx;
            posicaoTanqueZ -= dz;
        }
    }
    if (teclas['s']) {
        if(posicaoTanqueX>2.5&&posicaoTanqueX<397.5&&posicaoTanqueZ>2.5&&posicaoTanqueZ<397.5){
            posicaoTanqueX -= dx;
            posicaoTanqueZ -= dz;
        }
        if(posicaoTanqueX<2.5||posicaoTanqueX>397.5||posicaoTanqueZ<2.5||posicaoTanqueZ>397.5){
            posicaoTanqueX += dx;
            posicaoTanqueZ += dz;
        }
    }

    // Rotação com as teclas 'a' e 'd'
    if (teclas['a']) {
        anguloTanque += 5.0;
    }
    if (teclas['d']) {
        anguloTanque -= 5.0;
    }
    glutPostRedisplay();
    glutTimerFunc(16, atualizar, 0); // Aproximadamente 60 FPS
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tanque 3D");
    inicializar();
    glutDisplayFunc(exibir);
    glutKeyboardFunc(teclado);
    glutKeyboardUpFunc(tecladoSolto);
    glutSpecialFunc(teclasEspeciais); // Função para teclas especiais (setas)
    glutTimerFunc(25, atualizar, 0); // Atualiza a câmera
    glutMainLoop();
    return 0;
}
