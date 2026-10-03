/*
 * function: func_021F299C
 * address: 0x021F299C
 * packet: pkt_ov194_021F299C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: case 0 follows case 9; repeated stores in each case-8 arm preserve backward tail sharing.
 * symbols:
 *   func_021F2F8C 0x021F2F8C thumb ov194
 *   d_021F5544 0x021F5544 data a4
 *   d_021F5550 0x021F5550 data a4
 */
typedef struct {int x,y;} Pair;
typedef struct {int x,y,z,w;} Box;
extern int func_021F2F8C(Pair *,Pair *);
extern const int d_021F5544[],d_021F5550[];
int func_021F299C(Pair *p,Box *out)
{
 Pair xy;
 switch((unsigned)func_021F2F8C(p,&xy)) {
 case 1:out->x=d_021F5544[xy.y]+xy.x*2;out->y=d_021F5550[xy.y];out->z=out->x+2;out->w=out->y+3;break;
 case 2:case 3:case 4:case 5:out->x=(p->x+1)*3;out->y=20;out->z=out->x+3;out->w=out->y+3;break;
 case 6:out->x=25;out->y=8;out->z=out->x+4;out->w=out->y+3;break;
 case 7:out->x=24;out->y=12;out->z=out->x+5;out->w=out->y+3;break;
 case 8:if(p->x==0){out->x=3;out->y=16;out->z=out->x+4;out->w=out->y+3;}else {out->x=23;out->y=16;out->z=out->x+4;out->w=out->y+3;}break;
 case 9:out->x=15;out->y=20;out->z=out->x+12;out->w=out->y+3;break;
 case 0:return 0;
 }
 switch(p->y) {
 case 1:if(p->x>9)return 0;break;
 case 2:if(p->x>9)return 0;break;
 case 3:if(p->x>4)return 0;break;
 }
 return 1;
}
