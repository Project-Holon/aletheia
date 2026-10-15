/*
 * function: STARTMENU_LogoUpdate
 * address:  0x021B9BD4
 * packet:   pkt_ov088_021B9BD4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (52) runs 2 bytes past the compiled function (50);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 */

typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern u32 GPOWER_GetSpecialPowerId(void);

void STARTMENU_LogoUpdate(int *p)
{
    func_02040588(5, 0);
    BG_SYS_ResetSlot(6, 0, p[10] / 2);
    if (GPOWER_GetSpecialPowerId() == 0x15) {
        p[10]++;
    } else {
        p[10]--;
    }
}
