/*
 * function: BTL_SERVER_Create
 * address: 0x021BA9C8
 * packet: pkt_ov093_021BA9C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   gBtlServerFileName 0x021F3A60 data a4
 *   STRBUF_Create 0x020457B0 arm
 *   BTL_CALC_SetRngState 0x021D787C thumb ov093
 *   BTL_SERVER_ClearClient 0x021BB828 thumb ov093
 *   BTL_SERVER_FLOW_Create 0x021BB968 thumb ov093
 *   BTL_SERVER_FLOW_GetSlotTable 0x021BC550 thumb ov093
 *   BTL_SERVER_SetHandler 0x021BABEC thumb ov093
 *   BTL_SERVER_StepStart 0x021BAC04 thumb ov093
 */
#include "../include/Obj01234.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Copy24 { int x[6]; };
extern u8 gBtlServerFileName[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void BTL_CALC_SetRngState(void *);
extern void BTL_SERVER_ClearClient(u8 *p);
extern u8 *BTL_SERVER_FLOW_Create(void *a, void *b, void *c, void *d, int e, u16 heap);
extern u8 *BTL_SERVER_FLOW_GetSlotTable(u8 *p);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepStart(char *p, int *st);

u8 *BTL_SERVER_Create(void *a, struct Copy24 *b, void *c, int d, u16 heap)
{
    u8 *p;
    int i;
    p = func_02030734(heap, 0xcc4, 1, (const char *)gBtlServerFileName, 0xad);
    ((struct Obj01234 *)p)->fC = a;
    ((struct Obj01234 *)p)->f10 = c;
    ((struct Obj01234 *)p)->fCC0 = heap;
    ((struct Obj01234 *)p)->fCB0 = p + 0xf0;
    p[0xed] = 0;
    *(int *)&((struct Obj01234 *)p)->f44 = 0;
    p[0xcba] = 0;
    p[0xcbf] = 0;
    ((struct Obj01234 *)p)->f4C = d;
    *(struct Copy24 *)(p + 0x50) = *b;
    ((struct Obj01234 *)p)->fAC = (int)STRBUF_Create((int)0x20, (int)heap);
    BTL_CALC_SetRngState(b);
    for (i = 0; i < 4; i++)
        BTL_SERVER_ClearClient(p + 0x14 + i * 12);
    *(u8 * *)&((struct Obj01234 *)p)->f44 = BTL_SERVER_FLOW_Create(p, ((struct Obj01234 *)p)->fC, ((struct Obj01234 *)p)->f10, p + 0xf0, ((struct Obj01234 *)p)->f4C, ((struct Obj01234 *)p)->fCC0);
    ((struct Obj01234 *)p)->fB0 = BTL_SERVER_FLOW_GetSlotTable(*(u8 * *)&((struct Obj01234 *)p)->f44);
    BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepStart);
    return p;
}
