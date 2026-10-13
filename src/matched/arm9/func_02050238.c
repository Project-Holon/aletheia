/*
 * function: BILLBOARD_ACT_AddSlot
 * address:  0x02050238
 * packet:   pkt_020500B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Appends one {u16, u32} record (8 bytes, id in the low half) to the array
 * the caller's object keeps at +12, at the slot AREAMAN_Alloc hands back for
 * the pool at +20; the return is the slot narrowed to u16.
 *
 * The four bytes that cost three attempts are the first store's register
 * pairing: the pointer form `*(u16 *)(*(u32 *)((char *)p + 12) + idx * 8)`
 * compiles the same two instructions as the original but allocates them the
 * other way round (`ldr r1,[r6,#12]; lsl r2,r0,#3; strh r5,[r1,r2]` against
 * the original's r2/r1), a whole-function DIFF at +001C.  Written as an
 * array subscript on an 8-byte struct element,
 * `((struct S8 *)*(u32 *)((char *)p + 12))[idx].h`, it comes out EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_AddSlot.c \
 *       --func BILLBOARD_ACT_AddSlot --addr 0x02050238 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, 1 relocation site, resolved [label].
 *
 * symbols:
 *   AREAMAN_Alloc  0x02033CA8  arm
 */
#include "../include/Obj08867.h"

typedef unsigned short u16;
typedef unsigned int   u32;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

typedef signed int     s32;
struct AreaMan;
extern s32 AREAMAN_Alloc(struct AreaMan *p, u32 len);

u32 BILLBOARD_ACT_AddSlot(void *p, u32 b, u32 c)
{
    int idx = AREAMAN_Alloc((struct AreaMan *)(((struct Obj08867 *)p)->f14), 1);

    ((struct S8 *)((struct Obj08867 *)p)->fC)[idx].h = b;
    ((struct S8 *)((struct Obj08867 *)p)->fC)[idx].w = c;
    return (u16)idx;
}
