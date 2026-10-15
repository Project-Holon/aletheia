/*
 * function: INTRO_CMD_Create
 * address: 0x021BEF20
 * packet: pkt_ov204_021BEF20
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   INTRO_MSG_Create 0x021BF0A0 thumb ov204
 *   gIntroCmdSite 0x021C0AAC data a1
 *   gIntroSite  0x021C0AE4  data
 */
#include "../include/Obj03921.h"
#include "../include/Obj25381.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *gIntroSite, u16 tag);
extern char *INTRO_MSG_Create(u16 heap);
extern const char gIntroCmdSite[];
char *INTRO_CMD_Create(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    char *p = func_02030734(heap, 0x10d8, 1, gIntroCmdSite, 0x6f2);
    ((struct Obj03921 *)p)->f0 = heap;
    *(char * *)&((struct Obj03921 *)p)->f4 = d;
    ((struct Obj03921 *)p)->f8 = c;
    ((struct Obj03921 *)p)->fC = a;
    ((struct Obj03921 *)p)->f10 = b;
    ((struct Obj03921 *)p)->f14 = e;
    ((struct Obj03921 *)p)->fA4 = ((struct Obj25381 *)d)->fC;
    ((struct Obj03921 *)p)->f18 = INTRO_MSG_Create(heap);
    return p;
}
