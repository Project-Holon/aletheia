/*
 * function: C_GEAR_HandleCommand
 * address:  0x021F29D8
 * packet:   pkt_ov029_021F29D8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The listing extent (252 B) runs over the matched follower 0x021F2AB8;
 * the function is 224 B.  Case order 1/6, 5, 12/13, 7/11 is the table's
 * code order; the shared "sound; r = C_GEAR_StartPanelEvent" tails are cross-jumped.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   C_GEAR_IsCallTabActive  0x021F05B4  thumb  ov029
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   C_GEAR_StartSelectedRipple  0x021F3098  thumb  ov029
 *   C_GEAR_StepWaitSlots  0x021F3118  thumb  ov029
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StartPanelEvent  0x021F2EEC  thumb  ov029
 *   C_GEAR_NoOp  0x021F2CD4  thumb  ov029
 */
#include "../include/Obj00042.h"

struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
extern int C_GEAR_IsCallTabActive(unsigned char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int id);
extern void C_GEAR_StartSelectedRipple(u8 *p);
extern void C_GEAR_StepWaitSlots(void *p);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int a);
extern int C_GEAR_StartPanelEvent(char *p, int k);
extern void C_GEAR_NoOp(void);

int C_GEAR_HandleCommand(char *p, int a)
{
    int r = 0;
    void *b;

    GAMESYSTEM_GetGameComm((const struct Ctx *)*(int *)&((struct Obj00042 *)p)->f1C);
    b = GAMESYSTEM_GetFieldMap(((struct Obj00042 *)p)->f1C);
    if (a == 0 || b == 0)
        return 0;

    switch (((struct Obj00042 *)p)->f214) {
    case 1:
    case 6:
        if (C_GEAR_IsCallTabActive((unsigned char *)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54E);
            r = C_GEAR_StartPanelEvent(p, ((struct Obj00042 *)p)->f214);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x7E3);
            C_GEAR_StartSelectedRipple((u8 *)p);
            C_GEAR_ChangeStep(p, (void (*)(void))C_GEAR_StepWaitSlots, 0x1238);
        }
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54E);
        r = C_GEAR_StartPanelEvent(p, ((struct Obj00042 *)p)->f214);
        break;
    case 12:
    case 13:
        GFL_USE_PlaySeDefaultVolume(0x628);
        r = C_GEAR_StartPanelEvent(p, ((struct Obj00042 *)p)->f214);
        break;
    case 7:
    case 11:
        if (C_GEAR_IsCallTabActive((unsigned char *)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x628);
            r = C_GEAR_StartPanelEvent(p, ((struct Obj00042 *)p)->f214);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x7E3);
        }
        break;
    }

    if (r != 0) {
        ((struct Obj00042 *)p)->f218 = ((struct Obj00042 *)p)->f214;
        C_GEAR_ChangeStep(p, C_GEAR_NoOp, 0x1256);
    }
    ((struct Obj00042 *)p)->f214 = 0;
    return r;
}
