/*
 * function: IRCBATTLEMENU_SeqStartFadeOut
 * address:  0x02196804
 * packet:   pkt_ov021_02196804
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_02155A90  0x02155A90  thumb  ov010
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqWaitFadeEnd  0x021967BC  thumb  ov021
 */
#include "../include/Obj05988.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
struct Ctx;
struct Comm;
extern u32 func_02155A90(u8 *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void IRCBATTLEMENU_SetSeq(void *p, void *fn, u32 n);
extern void IRCBATTLEMENU_SeqWaitFadeEnd(u8 *p);

void IRCBATTLEMENU_SeqStartFadeOut(u8 *p)
{
    p[0x306] = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj05988 *)p)->f10);
    if (((struct Obj05988 *)p)->f8 != 0xC) {
        if (func_02026454((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4))) != 0) {
            GAME_COMM_RequestExitNoCallback((struct Comm *)GAMESYSTEM_GetGameComm((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4)));
        }
    }
    IRCBATTLEMENU_SetSeq(p, (void *)IRCBATTLEMENU_SeqWaitFadeEnd, 0x37C);
}
