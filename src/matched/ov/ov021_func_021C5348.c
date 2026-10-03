/*
 * function: func_021C5348
 * address:  0x021C5348
 * packet:   pkt_ov021_021C5348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts the fade sequence once (state 0 to 1).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02040588(u32 which, u32 enable);

void func_021C5348(u8 *p)
{
    if (*(u16 *)(p + 0x70) == 0) {
        *(u32 *)(p + 0x74) = 0;
        *(u32 *)(p + 0x78) = 0x19;
        func_02040588(1, 1);
        *(u16 *)(p + 0x70) = 1;
    }
}
