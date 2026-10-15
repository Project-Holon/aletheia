/*
 * function: NAMEIN_GRAPHIC_SymbolMove
 * address: 0x021F2BC8
 * packet: pkt_ov194_021F2BC8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 920 bytes through return at 021F2F5E; no calls or followers.
 */
void NAMEIN_GRAPHIC_SymbolMove(int *p,int *delta,unsigned char *s) {
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
