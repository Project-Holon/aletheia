/*
 * function: func_021BC114
 * address:  0x021BC114
 * packet:   pkt_ov088_021BC114
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   gStartMenuBattleFlagProcData     0x021BD824  data  a4
 *   ov088_id       0x00000058  data  a1
 */

typedef unsigned int   u32;
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern char gStartMenuBattleFlagProcData[];
extern char ov088_id[];

void func_021BC114(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)gStartMenuBattleFlagProcData, 2);
}
