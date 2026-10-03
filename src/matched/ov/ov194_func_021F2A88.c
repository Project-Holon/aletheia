/*
 * function: func_021F2A88
 * address: 0x021F2A88
 * packet: pkt_ov194_021F2A88
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 320-byte lead including padding, followed by existing matched 920-byte ov194_func_021F2BC8.
 */
typedef unsigned char u8;
void func_021F2A88(int *p,int *delta,u8 *saved)
{
 int enter,leave,x,y,index;
 enter=0;leave=0;
 switch(p[1]){
 case 0:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y==5)enter=1;
 break;
 case 4:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y==5)enter=1;
 break;
 case 5:
 x=p[0]+=delta[0];if(x<0)x=5;else if(x>5)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y!=5)leave=1;
 break;
 default:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 break;
 }
 if(enter){
  x=p[0];
  if(x>=6 && x<=9){saved[4]=x;p[0]=4;}
  else if(x>=10 && x<=12){saved[5]=x;p[0]=5;}
  else if(x>=0 && x<=5){index=x*2/3;saved[index]=x;p[0]=index;}
 }
 if(leave){
  x=p[0];
  if(x==4)p[0]=saved[4];
  else if(x==5)p[0]=saved[5];
  else if(x>=0 && x<=3)p[0]=saved[x];
 }
}
