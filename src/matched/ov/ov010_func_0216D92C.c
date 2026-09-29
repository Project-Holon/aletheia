/*
 * function: func_0216D92C
 * address:  0x0216D92C
 * packet:   pkt_ov010_0216D92C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: widens three signed bytes at p + 0x7e..0x80 to fixed
 * point (<< 12) and stores them into q[0..2].
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

void func_0216D92C(u8 *p, s32 *q)
{
    q[0] = *(s8 *)(p + 0x7e) << 12;
    q[1] = *(s8 *)(p + 0x7f) << 12;
    q[2] = *(s8 *)(p + 0x80) << 12;
}
