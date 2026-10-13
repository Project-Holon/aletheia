/*
 * function: STARTMENU_ChangeToIntroProc
 * address:  0x021BC0E4
 * packet:   pkt_ov088_021BC0E4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   d_021BD818     0x021BD818  data  a4
 *   ov088_id       0x00000058  data  a1
 */

typedef unsigned int   u32;
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern char d_021BD818[];
extern char ov088_id[];

void STARTMENU_ChangeToIntroProc(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD818, 0);
}
