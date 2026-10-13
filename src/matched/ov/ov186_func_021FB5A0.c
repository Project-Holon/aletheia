/*
 * function: func_021FB5A0
 * address:  0x021FB5A0
 * packet:   pkt_021FB5A0
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B84C  0x0204B84C  arm
 *   BMP_OAM_SetBgPriority  0x02025A0C  thumb
 */

extern void func_0204B84C(int, unsigned int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BMP_OAM_SetBgPriority(u8 *g, u32 a);

void func_021FB5A0(int *p, int b)
{
    func_0204B84C(p[0], b);
    BMP_OAM_SetBgPriority((u8 *)p[1], b);
}
