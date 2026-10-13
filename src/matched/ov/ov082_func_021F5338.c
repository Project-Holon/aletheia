/*
 * function: FLD_FACEUP_OpenEventMain
 * address:  0x021F5338
 * packet:   pkt_ov082_021F5338
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFaceUpWorkPtr  0x02189A60  thumb  ov021
 *   FLD_FACEUP_SetupBg  0x021F53B4  thumb  ov082
 *   FLD_FACEUP_StepFadeIn  0x021F5708  thumb  ov082
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06200.h"

typedef unsigned char u8;
typedef short s16;

typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u8 *FIELDMAP_GetFaceUpWorkPtr(u8 *p);
extern void FLD_FACEUP_SetupBg(u8 *w, int p);
extern int FLD_FACEUP_StepFadeIn(char *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int FLD_FACEUP_OpenEventMain(void *task, int *st)
{
    void *p;
    u8 *w;

    p = GAMESYSTEM_GetFieldMap(func_020124E4(task));
    w = *(u8 **)FIELDMAP_GetFaceUpWorkPtr(p);
    switch (*st) {
    case 0:
        FADE_Start(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            FLD_FACEUP_SetupBg(w, (int)p);
            FADE_Start(1, 0x10, 0, 0);
            (*st)++;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            *(s16 *)&((struct Obj06200 *)w)->f24 = 0;
            (*st)++;
        }
        break;
    case 3:
        if (FLD_FACEUP_StepFadeIn((char *)w) != 0)
            return 1;
        break;
    }
    return 0;
}
