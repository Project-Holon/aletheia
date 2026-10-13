/*
 * function: COMM_PLAYER_SetPackage
 * address:  0x02167848
 * packet:   pkt_02167848
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: callee of COLOSSEUM_UpdateCommPlayers (ov019) +005C.  An
 * unlabelled Thumb leaf inside ov010: `disasm.py` emitted its body as the
 * `pool_02167844` word run because its `push {r4, r5}` prologue saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  ov009 holds
 * ARM data at the address, ov011/ov018/ov019 only call it, so ov010 is the
 * region it lives in.
 *
 * The byte shape turns on the 12-byte aggregate copy: writing the +8 block as
 * one `struct { u64; u32; }` assignment is what makes mwcc evaluate the
 * destination address first (dst in r3, a2 kept in r2) and emit the exact
 * `ldm r5!`/`stm r4!` run.  Splitting it into a `u64` store plus a `u32` store
 * (or an explicit `dst` local, u32 index, Src/Dst structs) makes the allocator
 * compute the source address first and move a2 into r4, losing the whole range.
 * See docs/notes/recursive-match-unblocker-ov010-0215.c.txt and
 * docs/idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md.
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj12372.h"
#include "../include/Obj12373.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u64 lo;
    u32 hi;
} Blk12;

void COMM_PLAYER_SetPackage(char *a0, int a1, char *a2)
{
    char *d = a0 + a1 * 0x1C;

    *(Blk12 *)(d + 8) = *(Blk12 *)(a2 + 4);
    ((struct Obj12373 *)d)->f18 = ((struct Obj12372 *)a2)->f10;
    ((struct Obj12373 *)d)->f14 = ((struct Obj12372 *)a2)->f0;
}
