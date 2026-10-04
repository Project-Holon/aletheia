/*
 * function: func_021E7058
 * address: 0x021E7058
 * packet: pkt_ov119_021E7058
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021E7058(void *p)
{
    if (*(int *)((char *)p + 0xf24)) {
        func_0204B3B4((struct Obj *)(*(int *)((char *)p + 0xf24)));
        *(int *)((char *)p + 0xf24) = 0;
        *((char *)p + 0x11f5) = 0;
    }
}
