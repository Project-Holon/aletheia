/*
 * packet: pkt_ov186_021FFBD4
 * function: BR_POKESEARCH_Create
 * address: 0x021FFBD4
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_MEMBER_COUNT_GetU16Count 0x02200228 thumb ov186
 *   BR_POKESEARCH_HasSeenInGroup 0x0220014C thumb ov186
 *   gBrPokeSearchSourceFile 0x02200D9C data a1
 */
#include "../include/Obj01967.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *MI_CpuFill8(void *, int, unsigned);
extern u32 PRINTSYS_QUE_Create(void *p);
extern int BR_MEMBER_COUNT_GetU16Count(unsigned short, unsigned *);
extern int BR_POKESEARCH_HasSeenInGroup(void *p, u32 n, const u16 *ids);
extern const char gBrPokeSearchSourceFile[];
char *BR_POKESEARCH_Create(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap)
{
    char *p;
    int i = 0;
    p = func_02030734(heap, 0x90, 0, gBrPokeSearchSourceFile, 0x11a);
    MI_CpuFill8(p, 0, 0x90);
    ((struct Obj01967 *)p)->f24 = heap;
    ((struct Obj01967 *)p)->f7C = owner;
    ((struct Obj01967 *)p)->f28 = table;
    ((struct Obj01967 *)p)->f30 = c;
    ((struct Obj01967 *)p)->f34 = a;
    ((struct Obj01967 *)p)->f38 = b;
    ((struct Obj01967 *)p)->f3C = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj01967 *)p)->f24));
    *(int *)&((struct Obj01967 *)p)->f80 = BR_MEMBER_COUNT_GetU16Count((heap & 0x7fff) | 0x8000, (unsigned *)(p + 0x84));
    ((struct Obj01967 *)p)->f74 = d;
    ((struct Obj01967 *)p)->f78 = e;
    for (; i < 9; i++) *(unsigned char *)(p + i + 0x14) = BR_POKESEARCH_HasSeenInGroup(((struct Obj01967 *)p)->f7C, i, (const u16 *)(((struct Obj01967 *)p)->f80));
    return p;
}
