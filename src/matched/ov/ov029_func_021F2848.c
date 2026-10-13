/*
 * function: C_GEAR_Update
 * address:  0x021F2848
 * packet:   pkt_ov029_021F2848
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The listing extent (316 B) runs over an unlabelled 4-byte follower at
 * 0x021F2980 (`bx lr`); the function is 312 B.  C_GEAR_SetPowerState's second
 * argument is this function's r1, forwarded untouched.
 *
 * symbols:
 *   C_GEAR_SetPowerState  0x021F3144  thumb  ov029
 *   C_GEAR_IsAnyIndicatorShown  0x021F2DA8  thumb  ov029
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetRequestState  0x02158630  thumb  ov010
 *   C_GEAR_SetTabMode  0x021F06B8  thumb  ov029
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb
 *   FIELD_SOUND_SYSTEM_StopRingtone  0x02028A70  thumb
 *   C_GEAR_DeleteSplashActors  0x021F1BBC  thumb  ov029
 *   C_GEAR_SetAllActorsVisible  0x021F1A64  thumb  ov029
 *   C_GEAR_DrawAllCells  0x021F13FC  thumb  ov029
 *   C_GEAR_FadeBackground  0x021F0EB0  thumb  ov029
 *   C_GEAR_InitTabTimersPowerOn  0x021F0298  thumb  ov029
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StepClose  0x021F2370  thumb  ov029
 *   C_GEAR_StepIdle  0x021F2180  thumb  ov029
 *   func_02030D28  0x02030D28  arm
 */
#include "../include/Obj00761.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void C_GEAR_SetPowerState(u8 *p, int v);
extern int C_GEAR_IsAnyIndicatorShown(u8 *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetRequestState(int a);
extern void C_GEAR_SetTabMode(u8 *p, int a, int b);
struct BigObj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 WIH_DWC_PollStatus(void *key);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
struct SoundSys;
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void FIELD_SOUND_SYSTEM_StopRingtone(struct SoundSys *sys);
extern void C_GEAR_DeleteSplashActors(char *p);
extern void C_GEAR_SetAllActorsVisible(char *p, int flag);
extern void C_GEAR_DrawAllCells(void *p);
extern void C_GEAR_FadeBackground(char *p, int flag);
extern void C_GEAR_InitTabTimersPowerOn(u8 *p);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int line);
extern void C_GEAR_StepClose(char *p);
extern void C_GEAR_StepIdle(char *p);
extern void func_02030D28(struct Ctx *c);

void C_GEAR_Update(u8 *p, u8 v)
{
    int st;
    u32 keys;
    void *snd;

    if (p[0x451] == 1)
        return;

    C_GEAR_SetPowerState(p, v);
    if (C_GEAR_IsAnyIndicatorShown(p) == 0) {
        st = INTRUDE_COMM_GetRequestState(GAMESYSTEM_GetGameComm((const struct Ctx *)((struct Obj00761 *)p)->f1C));
        if (st == 3) {
            if (p[0x463] == 0) {
                C_GEAR_SetTabMode(p, 1, 0);
                p[0x463] = 1;
            }
        } else {
            if (p[0x463] == 1) {
                C_GEAR_SetTabMode(p, 0, 0);
                p[0x463] = 0;
            }
        }
        if (st == 0) {
            keys = WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj00761 *)p)->f1C))));
            snd = (void *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj00761 *)p)->f1C)));
            if (keys & 8) {
                if (p[0x462] == 0) {
                    p[0x462] = 1;
                    C_GEAR_SetTabMode(p, 1, 1);
                }
                FIELD_SOUND_SYSTEM_StartRingtone(snd);
            } else if ((keys & 8) == 0 && p[0x462] != 0) {
                FIELD_SOUND_SYSTEM_StopRingtone(snd);
                p[0x462] = 0;
                C_GEAR_SetTabMode(p, 0, 0);
            }
        }
    }

    if (p[0x451] == 2) {
        p[0x451] = 0;
        if (C_GEAR_IsAnyIndicatorShown(p) == 0) {
            C_GEAR_ChangeStep((char *)p, (void (*)(void))C_GEAR_StepClose, 0x11C5);
        } else {
            C_GEAR_DeleteSplashActors((char *)p);
            C_GEAR_SetAllActorsVisible((char *)p, 1);
            C_GEAR_DrawAllCells(p);
            C_GEAR_FadeBackground((char *)p, C_GEAR_IsAnyIndicatorShown(p));
            C_GEAR_InitTabTimersPowerOn(p);
            C_GEAR_ChangeStep((char *)p, (void (*)(void))C_GEAR_StepIdle, 0x11D4);
        }
    }

    if (*(void (**)(u8 *))p != 0)
        (*(void (**)(u8 *))p)(p);
    if (((struct Obj00761 *)p)->f204 != 0)
        func_02030D28((struct Ctx *)(((struct Obj00761 *)p)->f204));
}
