/*
 * function: HALL_OF_FAME_EnableBgEffects
 * address:  0x021B7300
 * packet:   pkt_021B7300
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041F28  0x02041F28  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02041F28(u32 which, u32 op, u16 value);

void HALL_OF_FAME_EnableBgEffects(char *a0)
{
    func_02041F28(3, 1, 1);
    func_02041F28(7, 1, 1);
}
