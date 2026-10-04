/*
 * function: func_021E69A4
 * address: 0x021E69A4
 * packet: pkt_ov119_021E69A4
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

void func_021E69A4(char *p)
{
    if (*(int *)(p + 0xfd4)) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0xfd4)));
        *(int *)(p + 0xfd4) = 0;
    }
}
