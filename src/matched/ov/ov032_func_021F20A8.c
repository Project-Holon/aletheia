/*
 * function: func_021F20A8
 * address: 0x021F20A8
 * packet: pkt_ov032_021F20A8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F20E4 0x021F20E4 thumb ov032
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj09799.h"
#include "../include/Obj20446.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F20E4(void *task, char *q);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);
void func_021F20A8(char *p, char *q, int *r)
{
    u8 *t;
    t = TCBL_GetWork(TCBL_AddTask(((struct Obj20446 *)p)->fA0, (void *)func_021F20E4, 0x10, 0));
    MI_CpuFill8(t, 0, 0x10);
    *(char * *)&((struct Obj09799 *)t)->f8 = p;
    *(char * *)&((struct Obj09799 *)t)->f4 = q;
    if (r != 0) {
        *(int * *)&((struct Obj09799 *)t)->fC = r;
        (*r)++;
    }
}
