/*
 * function: func_021F1F34
 * address:  0x021F1F34
 * packet:   pkt_ov032_021F1F34
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1F34 0x021F1F34 thumb
 *   func_021F1F9C 0x021F1F9C thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj04312.h"
#include "../include/Obj20439.h"
#include "../include/Obj20441.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F1F9C(void *task, u8 *s);
struct Chan02021FD8;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);

void func_021F1F34(char *p, u8 *q, int *r)
{
    u8 *t;

    t = TCBL_GetWork(TCBL_AddTask(((struct Obj20439 *)p)->fA0, (void *)func_021F1F9C, 0x14, 0));
    MI_CpuFill8(t, 0, 0x14);
    *(char * *)&((struct Obj04312 *)t)->fC = p;
    *(u8 * *)&((struct Obj04312 *)t)->f8 = q;
    t[2] = 2;
    t[3] = (q[0] + 4) << 4;
    PALANM_BlendChannel((struct Chan02021FD8 *)(((struct Obj20441 *)(*(char * *)&((struct Obj04312 *)t)->fC))->fAC), 3, t[3], 0x10, 4, 0x7fff);
    if (r != 0) {
        *(int * *)&((struct Obj04312 *)t)->f10 = r;
        (*r)++;
    }
}
