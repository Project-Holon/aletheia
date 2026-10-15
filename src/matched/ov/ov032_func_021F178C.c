/*
 * function: BEACON_VIEW_StartScrollStep
 * address:  0x021F178C
 * packet:   pkt_ov032_021F178C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_StartScrollStep 0x021F178C thumb
 *   BEACON_VIEW_ScrollStepTask 0x021F17D8 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj04311.h"
#include "../include/Obj20428.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct S02030FB4;
extern void BEACON_VIEW_ScrollStepTask(void *task, u8 *q);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);

void BEACON_VIEW_StartScrollStep(char *this, u8 a, int *p)
{
    u8 *r;
    int v;

    r = TCBL_GetWork(TCBL_AddTask(((struct Obj20428 *)this)->fA0, (void *)BEACON_VIEW_ScrollStepTask, 0xc, 0));
    MI_CpuFill8(r, 0, 0xc);
    r[0] = a;
    if (r[0] == 0) {
        r[3] = 0;
        v = 0x10;
    } else {
        v = 0x40;
        r[3] = v;
        v -= 0x50;
    }
    r[4] = v;
    r[1] = 4;
    *(int * *)&((struct Obj04311 *)r)->f8 = p;
    *p = *p + 1;
}
