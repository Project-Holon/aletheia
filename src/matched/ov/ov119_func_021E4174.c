/*
 * function: POKETRADE_2D_ClearSummaryBackground
 * address: 0x021E4174
 * packet: pkt_ov119_021E4174
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02040618 0x02040618 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void POKETRADE_2D_SetupSubBlend(void *);
extern void BG_SYS_ClearSlot(u32 i);
extern void func_02041B6C(u32 bit);
void POKETRADE_2D_ClearSummaryBackground(char *p)
{
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    POKETRADE_2D_SetupSubBlend(p);
    BG_SYS_ClearSlot(4);
    func_02041B6C(4);
}
