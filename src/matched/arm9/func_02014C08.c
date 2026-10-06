/*
 * function: func_02014C08
 * address:  0x02014C08
 * packet:   pkt_02014C08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020169E8  0x020169E8  thumb
 *   func_02016374  0x02016374  thumb
 *
 * Closed in the second pass (2026-09-22) from the 7-byte near miss in
 * docs/notes/pkt_02014C08.c.txt.  That note, and the two full permuter
 * runs made on it today (tools/permuter.py --mode hill, 171 single
 * mutations; --mode anneal, 2000 compiles) could not move the residue by
 * a single byte, which is the tell the brief names: a residue nothing in
 * the body reaches lives in the DECLARATIONS.
 *
 * THE LEVER IS func_02016374's ARITY.  The original leaves the slot
 * pointer live in r0 through the third bit test:
 *
 *     02014C7C  ldr r0, [r5, #0x14]     ; the slot array
 *     02014C7E  ldr r1, [sp, #4]        ; the offset constant 0x144
 *     02014C80  ldr r0, [r0, r4]        ; the slot -- STAYS in r0
 *     02014C82  ldr r1, [r0, r1]        ; the flag word into r1
 *     ...
 *     02014C8C  bl  #0x2016374          ; called with r0 already set
 *
 * Declared `void func_02016374(void)` the compiler has no reason to keep
 * the slot in r0, puts the flag word there instead and the six
 * instructions at +0x0076..+0x0080 come out with r0 and r1 swapped, the
 * whole 7-byte residue.  Declared `func_02016374(char *w)` and CALLED
 * with the slot, the allocation the image shows is the only legal one and
 * every byte closes.  This confirms the prototype
 * docs/families/mcss.h already carried (`void func_02016374(struct
 * McssWork *w)`), which the note had not applied at the call site.
 *
 * The 0x020169E8 site resolves through sole-ref/code (and, since
 * src/matched/func_020169E8.c was filed in the same pass, through
 * `matched` as well).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02014C08.c \
 *       --func func_02014C08 --addr 0x02014C08 --cc 1.1p1 --thumb
 */
#include "../include/Obj01459.h"
extern void func_020649D4(char *member, int value);
extern void func_02016374(void *obj);
typedef unsigned char  u8;
extern void func_020169E8(u8 *a0, u8 *a1);

typedef struct B1 { unsigned int b0 : 1; } B1;

void func_02014C08(char *self)
{
    int i;

    for (i = 0; i < ((struct Obj01459 *)self)->f10; i++) {
        if (*(int *)(((struct Obj01459 *)self)->f14 + i * 4) == 0)
            continue;
        if (((*(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x140) << 0x15) >> 0x1e) == 0)
            func_020649D4((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x34),
                          *(int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x174));
        if (((*(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x140) << 0x13) >> 0x1f) != 0)
            func_020169E8((u8 *)self, (u8 *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4)));
        if (((B1 *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x144))->b0 == 1) {
            func_02016374((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4)));
            func_020649D4((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x34), 0);
            *(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x144) &= ~1u;
        }
    }
}
