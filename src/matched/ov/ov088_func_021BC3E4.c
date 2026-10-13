/*
 * function: STARTMENU_BattleFlagProcMain
 * address:  0x021BC3E4
 * packet:   pkt_ov088_021BC3E4
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   d_021BD830     0x021BD830  data  a4
 */

typedef unsigned int u32;
extern void PROCSYS_PushGlobal(u32 a0, u32 a1, u32 a2);
struct Flags02008450;
extern void CONFIG_SetBattleFlag(struct Flags02008450 *p, int on);
extern char d_021BD830[];

int STARTMENU_BattleFlagProcMain(int a, int *st, int k, int *p)
{
    switch (*st) {
    case 0:
        if (k == 0) {
            PROCSYS_PushGlobal(-1, (u32)d_021BD830, (u32)p);
        } else if (k == 1) {
            CONFIG_SetBattleFlag((struct Flags02008450 *)p[1], 0);
        } else if (k == 2) {
            CONFIG_SetBattleFlag((struct Flags02008450 *)p[1], 1);
        }
        *st = *st + 1;
        break;
    case 1:
        return 1;
    }
    return 1;
}
