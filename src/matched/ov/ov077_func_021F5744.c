/*
 * function: ENCEFF_CellGridEventMain
 * address:  0x021F5744
 * packet:   pkt_ov077_021F5744
 * region:   ov077
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   ENCEFF_StepCellGrid  0x021F5798  thumb  ov077
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20795.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 ENCEFF_GetWork(u32 *p);
extern int ENCEFF_StepCellGrid(u8 *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int ENCEFF_CellGridEventMain(void *task, int *st)
{
    u8 *w;

    w = (u8 *)ENCEFF_GetWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)GAMESYSTEM_GetFieldMap(func_020124E4(task)))));
    switch (*st) {
    case 0:
        if (ENCEFF_StepCellGrid(w) == 0)
            break;
        FADE_Start(((struct Obj20795 *)w)->f3074, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
