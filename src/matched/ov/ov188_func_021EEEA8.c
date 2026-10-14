/*
 * function: BATTLE_REC_TOOL_UnpackSetup
 * address:  0x021EEEA8
 * packet:   pkt_021EEEA8
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BATTLE_REC_TOOL_UnpackParties  0x021EEFE4  thumb  ov188
 *   BATTLE_REC_TOOL_UnpackPlayers  0x021EF090  thumb  ov188
 *   BATTLE_REC_TOOL_UnpackInputLog  0x021EF1D8  thumb  ov188
 *   BATTLE_REC_TOOL_UnpackBattleRules  0x021EF2D4  thumb  ov188
 *   g_0214616C     0x0214616C  data
 */

#include "../include/G_BattleRec.h"

typedef unsigned int u32;

extern void BATTLE_REC_TOOL_UnpackParties(void *p, char *b, u32 c);
typedef unsigned char  u8;
extern void BATTLE_REC_TOOL_UnpackPlayers(u8 *a, u8 *b);
extern int BATTLE_REC_TOOL_UnpackInputLog(char *p, char *a1);
extern int BATTLE_REC_TOOL_UnpackBattleRules(u8 *a, const u8 *b);
extern struct BattleRec *g_0214616C;

void BATTLE_REC_TOOL_UnpackSetup(void *p, u32 c)
{
    char *q = ((char *)g_0214616C) + 0xc4;

    BATTLE_REC_TOOL_UnpackParties(p, q, c);
    BATTLE_REC_TOOL_UnpackPlayers(p, (u8 *)q);
    BATTLE_REC_TOOL_UnpackInputLog(p, q);
    BATTLE_REC_TOOL_UnpackBattleRules(p, (const u8 *)q);
}
