/*
 * function: INTRUDE_COMM_VIEW_WaitExitWipe
 * address: 0x021D4B30
 * packet: pkt_ov122_021D4B30
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_VIEW_SetCallback 0x021D4244 thumb ov122
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   GAME_COMM_GetKind  0x02026454  thumb  arm9
 */
#include "../include/Obj13964.h"
extern unsigned int WIPE_SYS_EndCheck(void);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 GAME_COMM_GetKind(void *obj);
extern void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2);
void INTRUDE_COMM_VIEW_WaitExitWipe(char *p)
{
    if (WIPE_SYS_EndCheck()) {
        if (((struct Obj13964 *)p)->f8 == 1) {
            if (!GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm(((struct Obj13964 *)p)->f354)))
                INTRUDE_COMM_VIEW_SetCallback(p, 0, 0x341);
        } else {
            INTRUDE_COMM_VIEW_SetCallback(p, 0, 0x345);
        }
    }
}
