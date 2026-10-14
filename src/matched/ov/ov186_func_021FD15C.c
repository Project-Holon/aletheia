/*
 * function: func_021FD15C
 * address:  0x021FD15C
 * packet:   pkt_ov186_021FD15C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_UTIL_Delete  0x021FC734  thumb  ov186
 *   BR_RES_ApplyBgSet  0x021FBDA4  thumb  ov186
 */

typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);

void func_021FD15C(void *p, int a1)
{
    BR_UTIL_Delete(p);
    BR_RES_ApplyBgSet(a1, 2);
}
