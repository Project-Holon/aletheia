/*
 * function: func_021F0E24
 * address:  0x021F0E24
 * packet:   pkt_ov032_021F0E24
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0E24  0x021F0E24  thumb
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char u8;

typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021F0E24(char *p)
{
    if (*(u8 *)(p + 0x7c) == 0) {
        func_0204B878((struct Obj *)(*(int *)(p + 0x2cc)), 0x10);
    } else {
        func_0204B878((struct Obj *)(*(int *)(p + 0x2cc)), 0xd);
    }
    if (*(u8 *)(p + 0x7c) + *(u8 *)(p + 0x7d) < *(u8 *)(p + 0x7b)) {
        func_0204B878((struct Obj *)(*(int *)(p + 0x2d0)), 0x11);
        return;
    }
    func_0204B878((struct Obj *)(*(int *)(p + 0x2d0)), 0x14);
}
