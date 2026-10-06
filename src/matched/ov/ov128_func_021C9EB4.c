/*
 * function: func_021C9EB4
 * address:  0x021C9EB4
 * packet:   pkt_021C9EB4
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void func_020452E8(struct Descriptor *d);

void func_021C9EB4(u8 *p, void *a1)
{
    int i;
    for (i = 0; i < 10; i++)
        func_020452E8(*(void **)(p + 0x128 + i * 8));
}
