/*
 * function: COLOSSEUM_SetupBattleMember
 * address:  0x02175358
 * packet:   pkt_ov012_02175358
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills the battle member entry of player i: the party pointer, the player
 * record address and the level limit of that player.  Called from
 * COLOSSEUM_SetupBattleInfo (0x02175280).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

typedef struct { s32 x, y, z; } VecFx32;
#include "../../ov010/comm_player_types.h"
#include "../union_comm_types.h"

/* One player of the battle (16 bytes; same layout as in colosseum.c). */
typedef struct ColosseumBattleMember {
    struct Party *party;
    ColosseumPlayer *player;
    u8 pad08;
    u8 levelLimit;      /* 0x09 */
    u8 pad0a[6];
} ColosseumBattleMember;

void COLOSSEUM_SetupBattleMember(ColosseumWork *colosseum, ColosseumBattleMember *member, int playerIndex)
{
    member->party = colosseum->party[playerIndex];
    member->player = &colosseum->player[playerIndex];
    member->levelLimit = colosseum->player[playerIndex].levelLimit;
}
