/*
 * function: func_021F0628
 * address:  0x021F0628
 * packet:   pkt_ov031_021F0628
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The store to +0x30 is written in both arms of an if/else (keeps the
 * empty `b` to the next instruction), and the loop condition is a
 * `? 1 : 0` ternary (keeps the entry branch to the bottom test).
 *
 * symbols:
 *   d_021F1038     0x021F1038  data  a1
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021F1038[];
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);

void func_021F0628(char *p, int sel)
{
    int i;
    int v;

    v = d_021F1038[sel];
    if (v == *(u8 *)(p + 0x30))
        *(u8 *)(p + 0x30) = 0;
    else
        *(u8 *)(p + 0x30) = v;
    for (i = 0; (i <= 4) ? 1 : 0; i++) {
        if (i == sel && *(u8 *)(p + 0x30) != 0)
            func_0204B6F4((struct Obj *)(*(u32 *)(p + 0x18 + i * 4)), 1, 1);
        else
            func_0204B6F4((struct Obj *)(*(u32 *)(p + 0x18 + i * 4)), 0, 1);
    }
}
