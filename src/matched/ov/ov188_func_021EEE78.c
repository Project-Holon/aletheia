/*
 * function: BATTLE_REC_TOOL_PackSetup
 * address:  0x021EEE78
 * packet:   pkt_021EEE78
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BATTLE_REC_TOOL_PackParties  0x021EEFA4  thumb  ov188
 *   BATTLE_REC_TOOL_PackPlayers  0x021EF014  thumb  ov188
 *   BATTLE_REC_TOOL_PackInputLog  0x021EF1AC  thumb  ov188
 *   BATTLE_REC_TOOL_PackBattleRules  0x021EF1F4  thumb  ov188
 *   g_0214616C     0x0214616C  data
 */

#include "../include/G_BattleRec.h"

typedef unsigned int u32;

extern void BATTLE_REC_TOOL_PackParties(int *a, char *p);
typedef unsigned char  u8;
extern void BATTLE_REC_TOOL_PackPlayers(u8 *a, u8 *b);
extern int BATTLE_REC_TOOL_PackInputLog(char *p, char *q);
extern int BATTLE_REC_TOOL_PackBattleRules(const u8 *a, u8 *b);
extern struct BattleRec *g_0214616C;

void BATTLE_REC_TOOL_PackSetup(void *p)
{
    char *q = ((char *)g_0214616C) + 0xc4;

    BATTLE_REC_TOOL_PackParties(p, q);
    BATTLE_REC_TOOL_PackPlayers(p, (u8 *)q);
    BATTLE_REC_TOOL_PackInputLog(p, q);
    BATTLE_REC_TOOL_PackBattleRules(p, (u8 *)q);
}
