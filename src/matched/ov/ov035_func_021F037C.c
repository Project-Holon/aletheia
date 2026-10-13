/*
 * function: C_GEAR_POWER_ONOFF_StepTurnOn
 * address:  0x021F037C
 * packet:   pkt_ov035_021F037C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_StepTurnOn 0x021F037C thumb
 *   C_GEAR_POWER_ONOFF_PrintMessage 0x021F0254 thumb ov035
 *   C_GEAR_POWER_ONOFF_ResetAndPrintMessage 0x021F0298 thumb ov035
 *   C_GEAR_POWER_ONOFF_OpenYesNoMenu 0x021F02FC thumb ov035
 *   C_GEAR_POWER_ONOFF_CloseMenu 0x021F0340 thumb ov035
 *   C_GEAR_POWER_ONOFF_UpdateMenu 0x021F0354 thumb ov035
 *   C_GEAR_POWER_ONOFF_GetMenuResult 0x021F0364 thumb ov035
 *   C_GEAR_POWER_ONOFF_IsMenuDecided 0x021F0370 thumb ov035
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 */
#include "../include/Obj01129.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void C_GEAR_POWER_ONOFF_PrintMessage(char *p, int a1, int a2);
extern void C_GEAR_POWER_ONOFF_ResetAndPrintMessage(char *p, int a1, int a2, int a3);
extern void C_GEAR_POWER_ONOFF_OpenYesNoMenu(char *p, int a1);
extern void C_GEAR_POWER_ONOFF_CloseMenu(char *p);
extern void C_GEAR_POWER_ONOFF_UpdateMenu(char *p);
extern u8 C_GEAR_POWER_ONOFF_GetMenuResult(char *p);
extern u32 C_GEAR_POWER_ONOFF_IsMenuDecided(char *p);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);
struct Comm;
struct Ctx;
struct IcaAnime;
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *h);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

int C_GEAR_POWER_ONOFF_StepTurnOn(char *p)
{
    u16 v;

    switch (((struct Obj01129 *)p)->f4A) {
    case 0:
        C_GEAR_POWER_ONOFF_PrintMessage(p, ((struct Obj01129 *)p)->f18, 0);
        C_GEAR_POWER_ONOFF_PrintMessage(p, ((struct Obj01129 *)p)->f1C, 3);
        C_GEAR_POWER_ONOFF_OpenYesNoMenu(p, ((struct Obj01129 *)p)->f0);
        (((struct Obj01129 *)p)->f4A)++;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            (((struct Obj01129 *)p)->f4A)++;
        break;
    case 2:
        if (C_GEAR_POWER_ONOFF_IsMenuDecided(p) != 0) {
            if (C_GEAR_POWER_ONOFF_GetMenuResult(p) == 0) {
                GAMESYSTEM_SetAlwaysNetFlag(((struct Obj01129 *)p)->f4, 1);
                GAMESYSTEM_TryStartAutoComm(((struct Obj01129 *)p)->f4);
                v = 3;
            } else {
                v = 5;
            }
            ((struct Obj01129 *)p)->f4A = v;
            C_GEAR_POWER_ONOFF_CloseMenu(p);
        }
        break;
    case 3:
        C_GEAR_POWER_ONOFF_ResetAndPrintMessage(p, ((struct Obj01129 *)p)->f18, 1, 6);
        (((struct Obj01129 *)p)->f4A)++;
        break;
    case 4:
        if (TOUCHPANEL_GetTrg() != 0 || GAMESYSTEM_IsNetOffBySleep(((struct Obj01129 *)p)->f4) != 0)
            (((struct Obj01129 *)p)->f4A)++;
        break;
    case 5:
        if (GAMESYSTEM_IsNetOffBySleep(((struct Obj01129 *)p)->f4) != 0) {
            if (GAME_COMM_GetKind(((struct Obj01129 *)p)->f8))
                GAME_COMM_RequestExitNoCallback(((struct Obj01129 *)p)->f8);
            ((struct Obj01129 *)p)->f4A = 6;
            break;
        }
        return 1;
    case 6:
        if (GAME_COMM_GetKind(((struct Obj01129 *)p)->f8) == 0)
            return 1;
        break;
    }
    C_GEAR_POWER_ONOFF_UpdateMenu(p);
    return 0;
}
