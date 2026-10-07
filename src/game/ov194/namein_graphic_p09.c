/*
 * file:     namein_graphic_p09.c
 * unit:     yes
 * function: func_021F2A88, func_021F2BC8, func_021F2F60, func_021F2F68
 * address:  0x021F2A88
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

void func_021F2A88(int *p,int *delta,u8 *saved);
void func_021F2BC8(int *p,int *delta,unsigned char *s);
int func_021F2F60(const int *p,int *out);
int func_021F2F68(const int *p,int *out);

/*
 * tail: 320-byte lead including padding, followed by existing matched 920-byte ov194_func_021F2BC8.
 */
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

/*
 * extent: 920 bytes through return at 021F2F5E; no calls or followers.
 */
void func_021F2BC8(int *p,int *delta,unsigned char *s) {
 int x,y;
 switch((unsigned)p[1]) {
 case 0:
 x=p[0]+=delta[0];if(x<0)x=10;else if(x>10)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==3) {
 switch((unsigned)p[0]) {
 case 8:case 9:s[8]=p[0];s[12]=p[0];s[11]=8;break;
 case 4:case 5:case 6:case 7:s[12]=p[0];s[11]=p[0];break;
 case 10:s[12]=10;s[11]=9;break;
 case 0:case 1:case 2:case 3:break;
 }
 switch(p[0]) {case 0:p[0]=s[6];break;case 1:case 2:p[0]++;break;default:p[0]=4;break;}
 } else {
 if(y!=1) {default:break;}
 switch((unsigned)p[0]) {
 case 8:case 9:s[8]=p[0];s[12]=p[0];x=p[0];if(x>9)x=9;else if(x<4)x=4;s[11]=x;break;
 case 4:case 5:case 6:case 7:case 10:s[12]=p[0];x=p[0];if(x>9)x=9;else if(x<4)x=4;s[11]=x;break;
 case 0:case 1:case 2:case 3:break;
 }
 switch(p[0]) {case 8:case 9:p[0]=8;break;case 10:p[0]=9;break;}
 }break;
 case 1:
 x=p[0]+=delta[0];if(x<0)x=9;else if(x>9)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==0) {
 switch(p[0]) {case 7:case 8:s[9]=p[0];break;}
 switch(p[0]) {case 8:p[0]=s[8];break;case 9:p[0]=10;break;}
 }else if(y==2) {
 switch(p[0]) {case 7:case 8:s[9]=p[0];break;}
 switch((unsigned)p[0]) {case 0:p[0]=s[7];break;case 7:case 8:p[0]=8;break;case 9:p[0]=9;break;default:p[0]++;break;}
 }break;
 case 2:
 x=p[0]+=delta[0];if(x<0)x=9;else if(x>9)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==1) {
 switch((unsigned)p[0]) {case 0:case 1:s[7]=p[0];break;case 4:case 5:case 6:case 7:case 8:case 9:s[11]=p[0];s[12]=p[0];break;case 2:case 3:break;}
 switch(p[0]) {case 0:case 1:p[0]=0;break;case 8:p[0]=s[9];break;case 9:p[0]=9;break;default:p[0]--;break;}
 }else if(y==3) {
 switch((unsigned)p[0]) {case 0:case 1:s[7]=p[0];break;case 4:case 5:case 6:case 7:case 8:s[11]=p[0];s[12]=p[0];break;case 9:s[11]=9;s[12]=10;break;case 2:case 3:break;}
 switch((unsigned)p[0]) {case 0:p[0]=s[10];break;case 1:case 2:case 3:break;default:p[0]=4;break;}
 }break;
 case 3:
 x=p[0]+=delta[0];if(x<0)x=4;else if(x>4)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==2) {
 switch(p[0]) {case 0:case 1:s[10]=p[0];s[6]=p[0];break;}
 switch((unsigned)p[0]) {case 0:case 1:case 2:case 3:break;case 4:p[0]=s[11];break;}
 }else if(y==0) {
 switch(p[0]) {case 0:case 1:s[10]=p[0];s[6]=p[0];break;}
 switch((unsigned)p[0]) {case 0:case 1:p[0]=0;break;case 2:case 3:p[0]--;break;case 4:p[0]=s[12];break;}
 }break;
 }
}

int func_021F2F60(const int *p,int *out) {return func_021F2F68(p,out);}

int func_021F2F68(const int *p,int *out) {
 if(p[1]<5) {if(out) {out[1]=p[1];out[0]=p[0];}return 1;}
 if(p[0]<=5)return p[0]+2;
 return 0;
}
