/*
 * function: func_021F18E0
 * address:  0x021F18E0
 * packet:   pkt_ov032_021F18E0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F18E0 0x021F18E0 thumb
 *   func_021F1930 0x021F1930 thumb
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Copy 0x02045838 arm
 */
#include "../include/Obj00007.h"
#include "../include/Obj09798.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F1930(void *task, u8 *s);
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void MI_CpuFill8(void *p, int v, int n);
struct U16Vec;
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);

void func_021F18E0(char *p, u32 a, int *c)
{
    u8 *r;

    r = TCBL_GetWork(TCBL_AddTask(*(u32 *)&((struct Obj00007 *)p)->fA0, (void *)func_021F1930, 0x10, 0));
    MI_CpuFill8(r, 0, 0x10);
    STRBUF_Copy((struct U16Vec *)(*(u32 *)&((struct Obj00007 *)p)->f120), (struct U16Vec *)a);
    *(char * *)&((struct Obj09798 *)r)->f8 = p;
    r[1] = 0x5a;
    BEACON_VIEW_SetArrowAnim((u8 *)p, 4, 2);
    *(int * *)&((struct Obj09798 *)r)->fC = c;
    (*c)++;
}
