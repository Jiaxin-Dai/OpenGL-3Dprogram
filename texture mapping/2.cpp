#include <stdlib.h>
#include <GL/glut.h>
#include <iostream.h>

GLfloat textureColor[3] = {0.0,0.0,1.0};//��ʱ����

void square(void)
{
//ָ���������꣬��������Ͷ������ɫ
	//�����������ģʽ����������s,t����1.0��begin
	
 	glBegin(GL_POLYGON);
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,0.0); 
		glVertex3f(-1.0,-1.0,0.0);

		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,1.0);  
		glVertex3f(-1.0,1.0,0.0);

		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(1.0,1.0); 
		glVertex3f(1.0,1.0,0.0);

		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(1.0,0.0); 
		glVertex3f(1.0,-1.0,0.0);
	glEnd();
	//�����������ģʽ����������s,t����1.0��end
	/*
	//�����������ģʽ����������s,t����1.0��begin
	glBegin(GL_POLYGON);
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,0.0); 
		glVertex3f(-1.0,-1.0,0.0);

		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,4.0); 
		glVertex3f(-1.0,1.0,0.0);

		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(4.0,4.0); 
		glVertex3f(1.0,1.0,0.0);

		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(4.0,0.0); 
		glVertex3f(1.0,-1.0,0.0);
	glEnd();
	//�����������ģʽ����������s,t����1.0��end
	*/

	/*
	//�����������ģʽ������������s,tС��1.0��begin
	glBegin(GL_POLYGON);
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,0.0); 
		glVertex3f(-1.0,-1.0,0.0);
		
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,2/3.0); 
		glVertex3f(-1.0,1.0,0.0);
		
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(2/3.0,2/3.0); 
		glVertex3f(1.0,1.0,0.0);
		
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(2/3.0,0.0); 
		glVertex3f(1.0,-1.0,0.0);
	glEnd();
	//�����������ģʽ������������s,tС��1.0��end
	*/

	/*
	//����������ɫ�Ͷ�����ɫ�Ļ�ϣ�begin
	glBegin(GL_POLYGON);
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,0.0); 
		glVertex3f(-1.0,-1.0,0.0);

		//glColor4f(0.0,1.0,0.0,0.5); 
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(0.0,1.0); 
		glVertex3f(-1.0,1.0,0.0);

		//glColor4f(0.0,0.0,1.0,0.5); 
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(1.0,1.0); 
		glVertex3f(1.0,1.0,0.0);

		//glColor4f(1.0,1.0,0.0,0.5);
		glColor4f(1.0,0.0,0.0,0.5);
		glTexCoord2f(1.0,0.0); 
		glVertex3f(1.0,-1.0,0.0);
	glEnd();
	//����������ɫ�Ͷ�����ɫ�Ļ�ϣ�End
	*/
}

void setTexture(void)//����ӳ�����ú���
{
	//��һ����������߶�����������ӳ���ͼ��
	//����Ĵ���ʵ���Ϲ�����һ��64x64��С��rgbͼ��
	//ÿ��4����ɫ�����Σ�4����ɫ�����Σ�ÿ�������α߳�Ϊ8�����س���
	GLubyte image[64][64][3];
    int i, j, c;
    for(i=0;i<64;i++)
    {
        for(j=0;j<64;j++)
		{
			c = (((i&0x8)==0)^((j&0x8)==0))*255;
			image[i][j][0]= (GLubyte) c;
			image[i][j][1]= (GLubyte) c;
			image[i][j][2]= (GLubyte) c;
			cout<<c<<' '<<endl;
		}
    }
	
	//�ڶ�������������ӳ�书��
	glEnable(GL_TEXTURE_2D);
	
	//������������ͼ��һ����ά����
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,64,64,0,GL_RGB,GL_UNSIGNED_BYTE, image);
	
	//���Ĳ����趨�������ģʽ��wrapping mode����ˮƽ�ʹ�ֱ�����REPEATģʽ��ȱʡģʽ��
	//Ϊ�˹۲����ģʽ��Ч������������ģʽ���볬��[0.0, 1.0]��Χ
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);//ˮƽ����
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);//��ֱ����
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	
	
	//���岽���趨����Ŵ����Сʱ���˲�ģʽ��filtering mode��,NEAREST�ٶȸ��죬��LINEAR��ƽ��
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);//����Ŵ�ʱ
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); //������Сʱ
	//glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
	
	//��ʱ���ܣ���������ͨ��glTexEnv�����趨������ɫ�뼸�ζ������������ɫ�ʣ�
	//��������ָ����ɫ�ʣ�Ҳ�����ǹ��ռ������ɫ�ʡ����ģʽ��combing mode����
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	//glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	//glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
	
	//glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_BLEND);//blendģʽ����Ҫ������ָ��������ɫ��
	//glTexEnvfv(GL_TEXTURE_ENV,GL_TEXTURE_ENV_COLOR,textureColor);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
		2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
		2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	square();
	glutSwapBuffers();
}

void main(int argc, char **argv)
{
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");

	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);

	setTexture();

    glutMainLoop();
}