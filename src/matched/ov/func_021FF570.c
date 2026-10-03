/*
 * function: func_021FF570
 * address:  0x021FF570
 * packet:   pkt_021FF570
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Program the 0x04000050 display register from the flag, or clear it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_0207D658(u32 addr, int plane, int brightness);

void func_021FF570(u32 v)
{
    if (v != 0) {
        func_0207D658(0x04000050, 0xa, v);
    } else {
        *(u16 *)0x04000050 = 0;
    }
}
