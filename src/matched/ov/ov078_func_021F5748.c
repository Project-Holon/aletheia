/*
 * function: ENCEFF_RippleEventMain
 * address:  0x021F5748
 * packet:   pkt_ov078_021F5748
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   ENCEFF_StepRipple  0x021F5950  thumb  ov078
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03671.h"

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_GetWork(u32 *p);
extern int ENCEFF_StepRipple(u8 *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int ENCEFF_RippleEventMain(void *task, int *st)
{
    u8 *w;

    w = (u8 *)ENCEFF_GetWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(task)))));
    switch (*st) {
    case 0:
        if (((struct Obj03671 *)w)->f19D8 != 0) {
            (((struct Obj03671 *)w)->f19D8)--;
        } else if (((struct Obj03671 *)w)->f19DC == 0) {
            FADE_Start(((struct Obj03671 *)w)->f19D4, 0, 0x10, 0);
            ((struct Obj03671 *)w)->f19DC = 1;
        }
        if (ENCEFF_StepRipple(w) != 0) {
            ((struct Obj03671 *)w)->f19C8 = 6;
            (*st)++;
        }
        break;
    case 1:
        if (((struct Obj03671 *)w)->f19C8 != 0) {
            (((struct Obj03671 *)w)->f19C8)--;
        } else if (FADE_IsActive() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
