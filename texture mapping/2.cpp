#include <stdlib.h>
#include <GL/glut.h>
#include <iostream.h>

GLfloat textureColor[3] = {0.0,0.0,1.0};//暂时不管

void square(void)
{
//指定顶点坐标，纹理坐标和顶点的颜色
	//测试纹理卷绕模式：纹理坐标s,t等于1.0：begin
	
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
	//测试纹理卷绕模式：纹理坐标s,t等于1.0：end
	/*
	//测试纹理卷绕模式：纹理坐标s,t大于1.0：begin
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
	//测试纹理卷绕模式：纹理坐标s,t大于1.0：end
	*/

	/*
	//测试纹理卷绕模式：：纹理坐标s,t小于1.0：begin
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
	//测试纹理卷绕模式：：纹理坐标s,t小于1.0：end
	*/

	/*
	//测试纹理颜色和对象颜色的混合：begin
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
	//测试纹理颜色和对象颜色的混合：End
	*/
}

void setTexture(void)//纹理映射设置函数
{
	//第一步：构造或者读入用于纹理映射的图像
	//下面的代码实际上构造了一个64x64大小的rgb图像，
	//每行4个黑色正方形，4个白色正方形，每个正方形边长为8个像素长：
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
	
	//第二步：启用纹理映射功能
	glEnable(GL_TEXTURE_2D);
	
	//第三步：载入图像到一个二维纹理
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,64,64,0,GL_RGB,GL_UNSIGNED_BYTE, image);
	
	//第四步：设定纹理卷绕模式（wrapping mode），水平和垂直方向的REPEAT模式是缺省模式。
	//为了观察卷绕模式的效果，纹理坐标模式必须超过[0.0, 1.0]范围
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);//水平方向
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);//垂直方向
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	
	
	//第五步：设定纹理放大或缩小时候滤波模式（filtering mode）,NEAREST速度更快，而LINEAR更平滑
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);//纹理放大时
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); //纹理缩小时
	//glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
	
	//暂时不管：第六步：通过glTexEnv函数设定纹理颜色与几何对象的明暗（或色彩）
	//【可以是指定的色彩，也可以是光照计算出的色彩】混合模式（combing mode）。
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	//glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	//glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
	
	//glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_BLEND);//blend模式，需要额外再指定纹理环境色彩
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