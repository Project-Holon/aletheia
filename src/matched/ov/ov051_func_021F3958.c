/*
 * function: FIELD_GIMMICK_D06_CreateSlideEvent
 * address:  0x021F3958
 * packet:   pkt_ov051_021F3958
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_D06_GetWork  0x021F3D6C  thumb  ov051
 *   FIELD_GIMMICK_D06_IsStoneNextToPanel  0x021F3C98  thumb  ov051
 *   FIELD_GIMMICK_D06_GetSlideSteps  0x021F3C84  thumb  ov051
 *   FIELD_GIMMICK_D06_EventSlideStone  0x021F39F8  thumb  ov051
 *   FIELD_GIMMICK_D06_EventStoneBlocked  0x021F3AB4  thumb  ov051
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082C60  0x02082C60  arm
 */
#include "../include/Obj06158.h"

extern void *FIELD_GIMMICK_D06_GetWork(int a);
extern int FIELD_GIMMICK_D06_IsStoneNextToPanel(int *a, int *b);
extern int FIELD_GIMMICK_D06_GetSlideSteps(int *a, int *b, int c);
extern int FIELD_GIMMICK_D06_EventSlideStone(int a, int *s, int *t);
extern int FIELD_GIMMICK_D06_EventStoneBlocked(int a, int *s, int *t);
extern int FIELDMAP_GetGameSystem(int a);
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082C60(void *a, int b, int c);

int FIELD_GIMMICK_D06_CreateSlideEvent(int a, int id, int arg)
{
    int sp3;
    int sp8;
    int sp1;
    unsigned short i;
    int v;
    char *r5;
    char *r7;
    unsigned short *r6;

    r5 = FIELD_GIMMICK_D06_GetWork(a);
    sp8 = FIELDMAP_GetGameSystem(a);
    for (i = 0; i < 12; i++) {
        v = *(int *)(r5 + 12 + i * 8);
        if (v == id)
            break;
    }
    if (i >= 12)
        i = 0;
    r7 = r5 + 12 + i * 8;
    if (FIELD_GIMMICK_D06_IsStoneNextToPanel((int *)r5, (int *)r7) == 1)
        return 0;
    sp3 = FIELD_GIMMICK_D06_GetSlideSteps((int *)r5, (int *)r7, arg);
    if (sp3 == 0)
        sp1 = (int)func_020122C0((void *)sp8, 0, FIELD_GIMMICK_D06_EventStoneBlocked, 0x10);
    else
        sp1 = (int)func_020122C0((void *)sp8, 0, FIELD_GIMMICK_D06_EventSlideStone, 0x10);
    r6 = func_020124E8((struct Obj *)sp1);
    func_02082C60(r6, 0, 0x10);
    r6[0] = arg;
    *(char * *)&((struct Obj06158 *)r6)->fC = r5;
    r6[1] = i;
    *(char * *)&((struct Obj06158 *)r6)->f8 = r7;
    ((struct Obj06158 *)r6)->f4 = sp3;
    return sp1;
}
