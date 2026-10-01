/*
 * function: func_021F38CC
 * address: 0x021F38CC
 * packet: pkt_ov194_021F38CC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021F265C 0x021F265C thumb ov194
 *   func_020355D8 0x020355D8 arm
 */
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F265C(char *,int *,int *);
extern void func_020355D8(unsigned);
int func_021F38CC(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(func_02035D20(&x,&y)) {
 point[0]=x;point[1]=y;
 if(func_021F265C(p,point,(int *)(p+0xD8))) {
 u=*(int *)(p+0xD8);out[3]=*(int *)(p+0xDC);out[1]=1;out[2]=u;func_020355D8(1);return 1;
 }}return 0;
}
