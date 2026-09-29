/*
 * function: func_021BAAA4
 * address:  0x021BAAA4
 * packet:   pkt_ov070_021BAAA4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020499D4  0x020499D4  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int func_020490F4(int a, u32 heap);
extern void func_020499D4(int, int, int, int, int, int, int, int);
extern void func_02049238(int);

void func_021BAAA4(int p, int mode)
{
    int h = func_020490F4(0x58, *(u16 *)(p + 0x544));

    if (mode != 2) {
        func_020499D4(h, 0x17, 5, 0, (u16)*(u32 *)(p + 0x800), 0, 0, *(u16 *)(p + 0x544));
    } else {
        func_020499D4(h, 0x18, 5, 0, (u16)*(u32 *)(p + 0x800), 0, 0, *(u16 *)(p + 0x544));
    }
    func_02049238(h);
}
