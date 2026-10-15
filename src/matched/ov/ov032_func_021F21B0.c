/*
 * function: BEACON_VIEW_StartWindowCTask
 * address:  0x021F21B0
 * packet:   pkt_ov032_021F21B0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_StartWindowCTask 0x021F21B0 thumb
 *   BEACON_VIEW_WindowCTask 0x021F21F8 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj07637.h"
#include "../include/Obj20452.h"
#include "../include/Obj20453.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct S02030FB4;
extern void BEACON_VIEW_WindowCTask(void *task, char *q);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);

void BEACON_VIEW_StartWindowCTask(char *p, char *q, int *r)
{
    void *t;
    u8 *s;

    t = TCBL_AddTask(((struct Obj20452 *)p)->fA0, (void *)BEACON_VIEW_WindowCTask, 0x10, 0);
    s = TCBL_GetWork(t);
    MI_CpuFill8(s, 0, 0x10);
    *(char * *)&((struct Obj07637 *)s)->f8 = p;
    *(char * *)&((struct Obj07637 *)s)->f0 = q;
    *(char * *)&((struct Obj07637 *)s)->f4 = q + 0x18;
    ((struct Obj20453 *)q)->f2C = t;
    if (r != 0) {
        *(int * *)&((struct Obj07637 *)s)->fC = r;
        (*r)++;
    }
}
