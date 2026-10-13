/*
 * function: C_GEAR_POWER_ONOFF_StepTurnOff
 * address:  0x021F0468
 * packet:   pkt_ov035_021F0468
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_StepTurnOff 0x021F0468 thumb
 *   C_GEAR_POWER_ONOFF_PrintMessage 0x021F0254 thumb ov035
 *   C_GEAR_POWER_ONOFF_OpenYesNoMenu 0x021F02FC thumb ov035
 *   C_GEAR_POWER_ONOFF_CloseMenu 0x021F0340 thumb ov035
 *   C_GEAR_POWER_ONOFF_UpdateMenu 0x021F0354 thumb ov035
 *   C_GEAR_POWER_ONOFF_GetMenuResult 0x021F0364 thumb ov035
 *   C_GEAR_POWER_ONOFF_IsMenuDecided 0x021F0370 thumb ov035
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 */
#include "../include/Obj01362.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void C_GEAR_POWER_ONOFF_PrintMessage(char *p, int a1, int a2);
extern void C_GEAR_POWER_ONOFF_OpenYesNoMenu(char *p, int a1);
extern void C_GEAR_POWER_ONOFF_CloseMenu(char *p);
extern void C_GEAR_POWER_ONOFF_UpdateMenu(char *p);
extern u8 C_GEAR_POWER_ONOFF_GetMenuResult(char *p);
extern u32 C_GEAR_POWER_ONOFF_IsMenuDecided(char *p);
extern u32 WIPE_SYS_EndCheck(void);
struct Comm;
struct Ctx;
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *h);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v);

int C_GEAR_POWER_ONOFF_StepTurnOff(char *p)
{
    u16 v;

    switch (((struct Obj01362 *)p)->f4A) {
    case 0:
        C_GEAR_POWER_ONOFF_PrintMessage(p, ((struct Obj01362 *)p)->f18, 2);
        C_GEAR_POWER_ONOFF_PrintMessage(p, ((struct Obj01362 *)p)->f1C, 3);
        C_GEAR_POWER_ONOFF_OpenYesNoMenu(p, ((struct Obj01362 *)p)->f0);
        (((struct Obj01362 *)p)->f4A)++;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            (((struct Obj01362 *)p)->f4A)++;
        break;
    case 2:
        if (C_GEAR_POWER_ONOFF_IsMenuDecided(p) != 0 || GAMESYSTEM_IsNetOffBySleep(((struct Obj01362 *)p)->f4) == 1) {
            if (C_GEAR_POWER_ONOFF_GetMenuResult(p) == 0 || GAMESYSTEM_IsNetOffBySleep(((struct Obj01362 *)p)->f4) == 1) {
                if (GAME_COMM_GetKind(((struct Obj01362 *)p)->f8))
                    GAME_COMM_RequestExitNoCallback(((struct Obj01362 *)p)->f8);
                v = 1;
            } else {
                v = 0;
            }
            ((struct Obj01362 *)p)->f4C = v;
            ((struct Obj01362 *)p)->f4A = 3;
            C_GEAR_POWER_ONOFF_CloseMenu(p);
        }
        break;
    case 3:
        if (((struct Obj01362 *)p)->f4C != 0) {
            if (GAME_COMM_GetKind(((struct Obj01362 *)p)->f8) != 0)
                break;
            GAMESYSTEM_SetAlwaysNetFlag(((struct Obj01362 *)p)->f4, 0);
        }
        (((struct Obj01362 *)p)->f4A)++;
        break;
    case 4:
        return 1;
    }
    C_GEAR_POWER_ONOFF_UpdateMenu(p);
    return 0;
}
