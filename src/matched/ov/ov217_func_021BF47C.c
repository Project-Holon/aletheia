/*
 * function: func_021BF47C
 * address:  0x021BF47C
 * packet:   pkt_ov217_021BF47C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_0204B3DC 0x0204B3DC arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF810(void *p);
extern void func_0204B3DC(u32 a, u32 b);
void func_021BF47C(char *p)
{
    if (*(u32 *)(p + 0x3c8) == 0 || func_021BF810(p) == 0) {
        func_0204B3DC(*(u32 *)(p + 0x39c), 0);
    } else {
        func_0204B3DC(*(u32 *)(p + 0x39c), 1);
    }
}
