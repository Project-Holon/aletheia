/*
 * function: func_021F28FC
 * address: 0x021F28FC
 * packet: pkt_ov194_021F28FC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F2F60 0x021F2F60 thumb ov194
 */
extern int func_021F2F60(const int *p, int *out);
int func_021F28FC(const int *p,int *out) {
 int xy[2];enum { X_LEFT=15,X_RIGHT=22 } x;int y;
 switch(func_021F2F60(p,xy)) {
 case 1:case 10:case 11:
 x=xy[0]*2+3;out[0]=x;y=xy[1]*3+5;out[1]=y;out[2]=x+2;out[3]=y+3;break;
 case 2:case 3:case 4:case 5:
 x=(p[0]+1)*3;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+3;out[3]=y+3;break;
 case 6:x=15;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 7:x=22;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 0:return 0;
 case 8:case 9:break;
 }
 if(p[1]==5 && p[0]>6)return 0;return 1;
}
