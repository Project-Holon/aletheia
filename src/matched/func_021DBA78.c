/*
 * function: func_021DBA78
 * address:  0x021DBA78
 * packet:   pkt_021DBA78
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204B878(void *, int);

void func_021DBA78(u8 *p, int i)
{
    func_0204B878(*(void **)(p + 8), (u16)(p[0] + i * 5));
}
