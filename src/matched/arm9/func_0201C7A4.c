/*
 * function: func_0201C7A4
 * address:  0x0201C7A4
 * packet:   pkt_0201C7A4
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
 *   _PrintJobWork     0x0214655C  data
 *
 * A printsys entry point: builds the shared print request in the static
 * scratch through PRINTSYS_SetupJob and hands it to PRINTSYS_RunJob with the
 * string object.  The leading STRBUF_GetChars(s) call's result is unused.
 *
 * Withdrawn 2026-09-24 (wave 20, lane 20G): the ../2.0/sp2 pin is retired.
 * The scratch address is held as an integer, a u32 local assigned
 * (u32)&_PrintJobWork and cast back at each site, matching func_0201C7D0.c.
 * Spelled this way, dsi/1.1p1 caches the address in a callee-saved
 * register and copies it into r0 at each site, byte-exact under the
 * default compiler.
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

void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w)
{
    u32 base;

    STRBUF_GetChars(s);
    base = (u32)&_PrintJobWork;
    PRINTSYS_SetupJob((struct PrintCtx *)base, w, x, y, z);
    PRINTSYS_RunJob((u8 *)((struct Scratch *)base), (int)s);
}
