/*
 * function: P_STA_SKILL_PrintStatsPage
 * address:  0x021D9E30
 * packet:   pkt_021D9E30
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   P_STA_SKILL_PrintStats  0x021DA0B0  thumb
 *   P_STA_SKILL_DrawHpBar  0x021DA3FC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void P_STA_SKILL_PrintStats(u8 *, u8 *);
extern void P_STA_SKILL_DrawHpBar(u8 *a, u8 *b);

void P_STA_SKILL_PrintStatsPage(void *a, int b)
{
    P_STA_SKILL_PrintStats(a, (u8 *)b);
    P_STA_SKILL_DrawHpBar(a, (u8 *)b);
}
