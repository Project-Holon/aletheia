/*
 * function: func_021F2F8C
 * address: 0x021F2F8C
 * packet: pkt_ov194_021F2F8C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef struct {int x,y;} Pair;
int func_021F2F8C(Pair *p,Pair *out) {
 int result;Pair xy;
 result=0;
 switch((unsigned)p->y) {
 case 0: if(p->x==10)result=6;else {xy=*p;result=1;}break;
 case 1: if(p->x==9)result=7;else {xy=*p;result=1;}break;
 case 2: if(p->x==0 || p->x==9)result=8;else {xy.x=p->x-1;xy.y=p->y;result=1;}break;
 case 3: result=9;if(p->x!=4)result=p->x+2;break;
 }
 if(result==1 && out) {*out=xy;}return result;
}
