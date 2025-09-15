/** 
    ***********************************************
    * @file caculate.c
    * @author rediduck
    * @version V1.0.0
    * @date 2025.9.14
    * @brief 运动解算
    ***********************************************
    * @attention
    * X型麦克纳姆轮安装方式十分特殊，在正方形安装
    * 方式下，并不能做到对z轴方向上的控制，故不推
    * 荐采用；在长方形安装方式下可以控制，但是效果
    * 没有O型安装方式好
    *  
    *               前
    *           ——————————          y
    *         1 |        | 2        |
    *                               |
    *         3 |        | 4        ——————>x
    *           ——————————
    *               后
    * 
    * *********************************************
*/
#include <stdio.h>


//从内向外看逆时针为正
float getV1backcalculate(float Lx,float Ly,float Vx,float Vy,float w)
{
    float Wrad = w/180.0*3.14;//角度转弧度
    float V1 = Vx-Vy+(Lx/2.0-Ly/2.0)*Wrad;
    return V1;
}

//从内向外看顺时针为正
float getV2backcalculate(float Lx,float Ly,float Vx,float Vy,float w)
{
    float Wrad = w/180.0*3.14;//角度转弧度
    float V2 = -Vx-Vy+(Lx/2.0+Ly/2.0)*Wrad;
    return V2;
}

//从内向外看顺时针为正
float getV3backcalculate(float Lx,float Ly,float Vx,float Vy,float w)
{
    float Wrad = w/180.0*3.14;//角度转弧度
    float V3 = Vx+Vy+(Lx/2.0+Ly/2.0)*Wrad;
    return V3;
}

//从内向外看逆时针为正
float getV4backcalculate(float Lx,float Ly,float Vx,float Vy,float w)
{
    float Wrad = w/180.0*3.14;//角度转弧度
    float V4 = -Vx+Vy+(Lx/2.0-Ly/2.0)*Wrad;
    return V4;
}


float getwcalculate(float Lx,float Ly,float V1,float V2,float V3,float V4)
{
    
    float w = (V1+V4)/(Lx-Ly)*180.0/3.14;
    return w;
}

float getVycalculate(float Lx,float Ly,float V1,float V2,float V3,float V4)
{
    float Vy = (Lx*V4+Ly*V1-Lx*V2+Ly*V2)/(2.0*(Lx-Ly));
    return Vy;
}

float getVxcalculate(float Lx,float Ly,float V1,float V2,float V3,float V4)
{
    float Vx = (Ly*V4+Lx*V1-Lx*V2+Ly*V2)/(2.0*(Lx-Ly));
    return Vx;
}






