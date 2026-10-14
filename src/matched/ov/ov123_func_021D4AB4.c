/*
 * function: GSYNC_MENU_StateWaitFadeOut
 * address: 0x021D4AB4
 * packet: pkt_ov123_021D4AB4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 */
#include "../include/Obj13969.h"
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
void GSYNC_MENU_StateWaitFadeOut(char *p)
{
    if (WIPE_SYS_EndCheck() != 0) {
        switch (((struct Obj13969 *)p)->f8) {
        case 2:
        case 3:
            if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm(((struct Obj13969 *)p)->f264)) == 0)
                GSYNC_MENU_ChangeState(p, 0, 0x345);
            break;
        default:
            GSYNC_MENU_ChangeState(p, 0, 0x349);
            break;
        }
    }
}
