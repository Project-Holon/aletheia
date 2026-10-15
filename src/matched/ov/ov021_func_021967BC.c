/*
 * function: IRCBATTLEMENU_SeqWaitFadeEnd
 * address:  0x021967BC
 * packet:   pkt_ov021_021967BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   IRC_BATTLE_ENTRY_GetGameSys  0x02155A90  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 */
#include "../include/Obj12631.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 WIPE_SYS_EndCheck();
struct Ctx;
extern u32 IRC_BATTLE_ENTRY_GetGameSys(u8 *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern void IRCBATTLEMENU_SetSeq(void *p, u32 a, u32 b);

void IRCBATTLEMENU_SeqWaitFadeEnd(u8 *p)
{
    if (WIPE_SYS_EndCheck()) {
        if (((struct Obj12631 *)p)->f8 != 0xC) {
            if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)
                    IRC_BATTLE_ENTRY_GetGameSys((u8 *)((struct Obj12631 *)p)->f2E4))) == 0)
                IRCBATTLEMENU_SetSeq(p, 0, 0x361);
        } else {
            IRCBATTLEMENU_SetSeq(p, 0, 0x365);
        }
    }
}
