/*
 * function: func_02051394
 * address:  0x02051394
 * packet:   pkt_02051394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A88     0x02146A88  data
 *   func_020528A8  0x020528A8  arm
 *   func_020528BC  0x020528BC  arm
 *   func_020528D0  0x020528D0  arm
 *   func_02052984  0x02052984  arm
 *
 * Publishes the emitter into the singleton's current-emitter slot (+0x44 of
 * the 0x02146A88 pointee, i.e. word index 0x11), routes each of the emitter's
 * two handler words at +0x18 and +0x1C to one of two handlers on null, then
 * clears the slot again.
 *
 * CLOSES the wall recorded in docs/notes/pkt_02051394.c.txt, which was not a
 * codegen residue at all: the note's two unresolved sites 0x020528A8 and
 * 0x020528BC are now EXACT entries of shard pkt_020526A8, so both attest
 * through `sole-ref/code` and the file needed only its remaining 10-byte
 * codegen gap closed.
 *
 * That gap was statement form.  The condition field and the call's argument
 * must both be read into NAMED LOCALS, and by plain ASSIGNMENT STATEMENTS
 * placed after the publish store, not by initialisers at the declarations:
 *   - inline (`if (p[6] == 0) func_020528BC(p[0]);`) the compiler folds the
 *     condition into r0 and issues `cmp` before the argument load, so the
 *     image's `ldr r1, [r4, #0x18]` / `ldr r0, [r4]` / `cmp r1, #0` triple
 *     comes out in the wrong order in BOTH blocks (10 bytes out);
 *   - as initialisers at the top of the body the two loads hoist ABOVE the
 *     `str r4, [r0, #0x44]` publish and the first block loses six more bytes
 *     (14 out).
 * Assignment statements after the store reproduce all 25 instructions.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051394.c \
 *       --func func_02051394 --addr 0x02051394 --cc 1.1p1 --arm
 */

#include "../include/G_02146A88.h"

typedef unsigned int u32;

extern struct G_02146A88 *g_02146A88;
extern void func_020528A8(u32 a);
extern void func_020528BC(u32 a);
extern int  func_020528D0(u32 o, u32 alloc);
extern int  func_02052984(u32 o, u32 alloc);

void func_02051394(u32 *p)
{
    u32 a;
    u32 v;

    ((u32 *)g_02146A88)[0x11] = (u32)p;

    a = p[6];
    v = p[0];
    if (a == 0)
        func_020528BC(v);
    else
        func_02052984(v, a);

    a = p[7];
    v = p[0];
    if (a == 0)
        func_020528A8(v);
    else
        func_020528D0(v, a);

    ((u32 *)g_02146A88)[0x11] = 0;
}
