/*
 * function: FLD_FACEUP_CloseEventMain
 * address:  0x021F55A0
 * packet:   pkt_ov082_021F55A0
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
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   func_02030EAC  0x02030EAC  arm
 *   FLD_FACEUP_Release  0x021F5648  thumb  ov082
 */
#include "../include/Obj05164.h"

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned char  u8;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u8 *FIELDMAP_GetFaceUpWorkPtr(u8 *p);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int  FADE_IsActive(void);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void FLD_FACEUP_Release(void *a, void *p);

int FLD_FACEUP_CloseEventMain(void *a0, int *st)
{
    void *obj;
    char *w;
    int t;

    obj = GAMESYSTEM_GetFieldMap(func_020124E4(a0));
    w = *(char **)FIELDMAP_GetFaceUpWorkPtr(obj);
    switch (*st) {
    case 0:
        if (((struct Obj05164 *)w)->f70 != 0)
            FADE_Start(3, 0, 0x10, -8);
        else
            FADE_Start(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (FADE_IsActive() != 0)
            break;
        func_02030EAC((struct Node *)(((struct Obj05164 *)w)->f14));
        (*st)++;
        break;
    case 2:
        if (((struct Obj05164 *)w)->f2C != 0)
            break;
        if (((struct Obj05164 *)w)->f50 != 0)
            break;
        func_02030EAC((struct Node *)(((struct Obj05164 *)w)->f18));
        t = ((struct Obj05164 *)w)->f70;
        FLD_FACEUP_Release(obj, w);
        if (t != 0)
            return 1;
        FADE_Start(1, 0x10, 0, 0);
        (*st)++;
        break;
    case 3:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
