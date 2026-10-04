/*
 * function: func_021F1DB0
 * address: 0x021F1DB0
 * packet: pkt_ov029_021F1DB0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021F1DB0(char *p)
{
    if (*(int *)(p + 0x164) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x164)));
        *(int *)(p + 0x164) = 0;
    }
    if (*(int *)(p + 0x168) != 0)
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x168)));
    if (*(int *)(p + 0x16c) != 0) {
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x16c)));
        *(int *)(p + 0x16c) = 0;
    }
}
