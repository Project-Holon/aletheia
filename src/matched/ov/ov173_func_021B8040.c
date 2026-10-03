/*
 * function: func_021B8040
 * address: 0x021B8040
 * packet: pkt_ov173_021B8040
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021B8040(u8 *p)
{
    if(*(u8 *)(p+440)<=4) {
        func_0204B878(*(void **)(p+264),17);
        func_0204B878(*(void **)(p+260),16);
        return;
    }
    if(*(u16 *)(*(u8 **)p+22)+4 < *(u8 *)(p+440)) {
        func_0204B878(*(void **)(p+264),17);
        func_0204B878(*(void **)(p+260),2);
        return;
    }
    if(*(u16 *)(*(u8 **)p+22)==0) {
        func_0204B878(*(void **)(p+264),3);
        func_0204B878(*(void **)(p+260),16);
    }
}
