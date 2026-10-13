/*
 * function: EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn
 * address:  0x021BEF8C
 * packet:   pkt_ov021_021BEF8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_SetUpdateStopped  0x02189A58  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   FADE_Start  0x0204E720  arm
 *   func_0208068C  0x0208068C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   SYMBOL_MAP_StopBg2Scale  0x02166B2C  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes  0x021BF564  thumb  ov021
 *   FIELDMAP_ResetBgAffineHideMsg  0x02188DF0  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_IsSetupDone  0x021903CC  thumb  ov021
 *   FIELD_MSGBG_LoadWindowGraphicsStep  0x021902AC  thumb  ov021
 */
#include "../include/Obj01504.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELDMAP_SetUpdateStopped(u8 *p, u32 v);
typedef signed int     s32;
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void func_0208068C(u32 a);
extern void MIi_CpuClearFast(u32 a, u32 b, u32 c);
extern void func_02080B98(void);
extern void func_0207FDCC(u32 a);
extern void SYMBOL_MAP_StopBg2Scale(void);
extern void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(u32 a);
extern void FIELDMAP_ResetBgAffineHideMsg(u8 *a);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_IsSetupDone(u8 *p);
extern void FIELD_MSGBG_LoadWindowGraphicsStep(u16 *p, int v);

int EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn(u32 p0, int *st, u8 *q)
{
    u32 m;

    switch (*st) {
    case 0:
        FIELDMAP_SetUpdateStopped((u8 *)(((struct Obj01504 *)q)->f4), 1);
        ((struct Obj01504 *)q)->f1C = 0x10;
        func_0204047C(2, 0);
        func_0204047C(0, 1);
        func_02040588(0, 1);
        func_0207D63C(0x04000050, 4, 1, ((struct Obj01504 *)q)->f1C, 0);
        FADE_Start(((struct Obj01504 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj01504 *)q)->f1C != 0) {
            ((struct Obj01504 *)q)->f1C = ((struct Obj01504 *)q)->f1C - 1;
            *(volatile u16 *)0x04000052 = ((0x10 - ((struct Obj01504 *)q)->f1C) << 8) | ((struct Obj01504 *)q)->f1C;
            break;
        }
        func_02040588(2, 0);
        func_0208068C(8);
        MIi_CpuClearFast(0, 0x06800000, 0x20000);
        func_02080B98();
        func_0207FDCC(8);
        SYMBOL_MAP_StopBg2Scale();
        *st = *st + 1;
        break;
    case 2:
        EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(((struct Obj01504 *)q)->f4);
        *st = *st + 1;
        break;
    case 3:
        FIELDMAP_ResetBgAffineHideMsg((u8 *)(((struct Obj01504 *)q)->f4));
        *st = *st + 1;
        break;
    case 4:
        m = FIELDMAP_GetMsgBg((u8 *)(((struct Obj01504 *)q)->f4));
        if (FIELD_MSGBG_IsSetupDone((u8 *)m) != 0) {
            FIELD_MSGBG_LoadWindowGraphicsStep((u16 *)m, 0);
            *st = *st + 1;
        }
        break;
    case 5:
        FIELD_MSGBG_LoadWindowGraphicsStep((u16 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj01504 *)q)->f4)), 1);
        *st = *st + 1;
        break;
    case 6:
        FIELD_MSGBG_LoadWindowGraphicsStep((u16 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj01504 *)q)->f4)), 2);
        *st = *st + 1;
        break;
    case 7:
        *st = *st + 1;
    case 8:
        FIELDMAP_SetUpdateStopped((u8 *)(((struct Obj01504 *)q)->f4), 0);
        return 1;
    }
    return 0;
}
