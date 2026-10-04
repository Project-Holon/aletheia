/*
 * function: func_021AE030
 * address:  0x021AE030
 * packet:   pkt_ov021_021AE030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);

void func_021AE030(u32 a, u32 *out)
{
    u32 *p = (u32 *)func_021AC1AC(a);

    *out = p[0];
    func_021AC1CC(a, p + 1);
}
