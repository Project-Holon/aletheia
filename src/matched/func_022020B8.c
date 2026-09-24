/*
 * function: func_022020B8
 * address:  0x022020B8
 * packet:   pkt_022020B8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4FC4  0x021F4FC4  thumb  ov135

 * When the mode query answers 2, publish the u16 at +0xe0e and hand the object back.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_020120F4(u32 v);
extern u32 func_02012DD0(u32 v);
extern void func_021F4FC4(u8 *p);

int func_022020B8(u8 *p)
{
    if (func_02012DD0(func_020120F4(*(u32 *)(*(u32 *)p + 0x40))) == 2) {
        *(u32 *)(p + 0x28) = *(u16 *)(p + 0xe0e);
        func_021F4FC4(p);
    }
    return 2;
}
