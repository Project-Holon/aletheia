/*
 * function: func_021B7264
 * address: 0x021B7264
 * packet: pkt_ov101_021B7264
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * func_020282A4 0x020282A4 thumb
 * func_02028218 0x02028218 thumb
 */
typedef unsigned int   u32;
struct Obj;
extern void func_020282A4(struct Obj *obj);
extern void func_02028218(struct Obj *obj, u32 a);
void func_021B7264(int p) {
 func_020282A4((struct Obj *)(*(int *)p));
 func_02028218((struct Obj *)(*(int *)p),0);
 *(int *)(p+0x50)=0;
}
