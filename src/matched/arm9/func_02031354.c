/*
 * function: PROCSYS_CreateInternal
 * address:  0x02031354
 * packet:   pkt_02031354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_020A783C  0x020A783C  data
 *
 * Allocates a 0x20-byte node and lays down a sentinel ring: the first
 * halfword is the caller's key, +4 and +0x14 hold -1 (the two ends of a list
 * with no members) and every other word is 0.  The linker merges the two
 * adjacent zero stores at +4/+8 into one `stmib r0, {r1, r4}`.
 *
 * The first argument handed to func_02030734 is the caller's own parameter -
 * the original never writes r0 before the call, so r0 still holds a0.  A
 * literal first argument makes the compiler materialise it and shifts the
 * whole prologue.
 *
 * The pool word 0x020A783C is a `literal` site: it appears in ten other
 * pools in the image, e.g. 0x0203158C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PROCSYS_CreateInternal.c \
 *       --func PROCSYS_CreateInternal --addr 0x02031354 --cc 1.1p1 --arm
 */
#include "../include/Obj03442.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern char data_020A783C[];

void *PROCSYS_CreateInternal(int a0)
{
    char *p = func_02030734(a0, 0x20, 0, (const char *)((int)data_020A783C), 0xc5);

    ((struct Obj03442 *)p)->f0 = a0;
    ((struct Obj03442 *)p)->f4 = -1;
    ((struct Obj03442 *)p)->f8 = 0;
    ((struct Obj03442 *)p)->fC = 0;
    ((struct Obj03442 *)p)->f10 = 0;
    ((struct Obj03442 *)p)->f14 = -1;
    ((struct Obj03442 *)p)->f18 = 0;
    ((struct Obj03442 *)p)->f1C = 0;
    return p;
}
