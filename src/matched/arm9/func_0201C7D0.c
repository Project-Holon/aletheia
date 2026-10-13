/*
 * function: PRINTSYS_PrintColor
 * address:  0x0201C7D0
 * packet:   pkt_0201C7D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetChars  0x02045A90  arm
 *   PRINTSYS_SetupJob   0x0201C808  thumb
 *   PRINTSYS_RunJob  0x0201C8BC  thumb
 *   PRINTSYS_SetJobColor   0x0201C8A4  thumb
 *   _PrintJobWork     0x0214655C  data
 *
 * A printsys entry point: the PRINTSYS_Print body plus a
 * PRINTSYS_SetJobColor(scratch, v) step between building the shared print request
 * in the static scratch and handing it to PRINTSYS_RunJob.  The leading
 * STRBUF_GetChars(s) call's result is unused.
 *
 * What closed it (wave 20): the scratch address is held as an integer, a
 * u32 local assigned (u32)&_PrintJobWork and cast back at each of the three
 * sites.  Spelled `&_PrintJobWork` at every site, 1.1p1 value-numbers the
 * address once, caches it in r4 and schedules z's outgoing stack store
 * straight after the first call to free that register (37 bytes out).
 * Through the integer local the address is rematerialised from its one pool
 * word at every site, z stays in r4 until its store after r0..r3 as the
 * image does, and the stacked u16 read keeps the 1.1p1 base.  This retires
 * the ../2.0/sp2 near miss (2 out) the notes carried.
 */

#include "../include/G_Scratch.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern struct Scratch _PrintJobWork;

struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
struct PrintCtx;
extern void PRINTSYS_SetupJob(struct PrintCtx *p, void *w, void *x, u32 y, s16 z);
extern void PRINTSYS_RunJob(u8 *a0, int a1);
struct Rec2;
extern void PRINTSYS_SetJobColor(struct Rec2 *p, u16 v);

void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v)
{
    u32 base;

    STRBUF_GetChars(s);
    base = (u32)&_PrintJobWork;
    PRINTSYS_SetupJob((struct PrintCtx *)base, w, x, y, z);
    PRINTSYS_SetJobColor((struct Rec2 *)base, v);
    PRINTSYS_RunJob((u8 *)((struct Scratch *)base), (int)s);
}
