/*
 * function: func_021D8C0C
 * address: 0x021D8C0C
 * packet: pkt_ov119_021D8C0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef signed short s16;
extern unsigned func_02035CB8(int *,int *);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern int func_0204B404(int,void *,int);
void func_021D8C0C(void *p) {
 int x,y; s16 pos[2];
 if(*(int *)((char *)p+0xf60)!=0) {
 if(func_02035CB8(&x,&y)!=0) {
 func_0204B454((struct Actor *)*(int *)((char *)p+0xf60),(struct PtS *)((char *)p+0xf6c),1);
 pos[0]=x+*(s16 *)((char *)p+0xf68);
 pos[1]=y+*(s16 *)((char *)p+0xf6a);
 if(pos[1]>150) pos[1]=150;
 func_0204B404(*(int *)((char *)p+0xf60),pos,1);
 }
 }
}
