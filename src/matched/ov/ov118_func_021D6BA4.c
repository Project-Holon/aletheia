/*
 * function: POKETRADE_DEMO_MIDDLE_StepMessage
 * address:  0x021D6BA4
 * packet:   pkt_ov118_021D6BA4
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_MIDDLE_PrintMessage  0x021D6AD4  thumb  ov118
 *   MCSS_GetPosition  0x02015C30  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   POKETRADE_SAVE_IsMessagePrintDone  0x021E12AC  thumb  ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear  0x021E1098  thumb  ov119
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_DEMO_MIDDLE_StepSetup  0x021D6F90  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00984.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void POKETRADE_DEMO_MIDDLE_PrintMessage(u8 *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_3D_DeleteMcssSlot(void *p, int a);
extern u32 func_020307B0(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_MCSS_SlideUpdate(void *p, int a1);
extern void POKETRADE_DEMO_MIDDLE_StepSetup(u8 *p);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define SLOT0 (*(u32 *)(p + 0x85C))

void POKETRADE_DEMO_MIDDLE_StepMessage(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        POKETRADE_DEMO_MIDDLE_PrintMessage(p);
    }
    if (((struct Obj00984 *)p)->f11ED == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone((char *)p) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear((char *)p);
        if (((struct Obj00984 *)p)->f11ED == 0) {
            POKETRADE_3D_DeleteMcssSlot(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (int)p);
}
