/*
 * function: func_021B7FD0
 * address: 0x021B7FD0
 * packet: pkt_ov173_021B7FD0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0204B878(void *,unsigned);
extern void func_0204B8C4(void *,int);
void func_021B7FD0(u8 *p,int direction)
{
    func_0204B8C4(*(void **)(p+264),0);
    func_0204B8C4(*(void **)(p+260),0);
    if(direction>0) {
        if(*(u16 *)(*(u8 **)p+22)+4 < *(u8 *)(p+440)) func_0204B878(*(void **)(p+260),10);
        else func_0204B878(*(void **)(p+260),23);
        func_0204B878(*(void **)(p+264),3);
    } else {
        if(*(u16 *)(*(u8 **)p+22)==0) func_0204B878(*(void **)(p+264),24);
        else func_0204B878(*(void **)(p+264),11);
        func_0204B878(*(void **)(p+260),2);
    }
}
