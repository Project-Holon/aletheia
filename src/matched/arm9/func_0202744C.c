/*
 * unit:     no
 * address:  0x0202744C
 * packet:   pkt_020271F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202744C
 *
 * Sets the low byte of the halfword at +0x48 of its argument to the
 * constant 5, leaving the high byte untouched. Called from every
 * trampoline of src/matched/unit_020271F8.c as a shared "mark this event
 * object pending" step, independent of which event id was just written.
 *
 * `disasm.py` measures this function's extent to the next label at
 * 0x020274B4, 104 bytes away, but only the first 20 bytes belong to it;
 * what follows is a second, unlabelled function (the same
 * "half the accessors are printed as .word data" gap
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md describes)
 * that packs several bitfields of the same object from a small argument
 * struct. It is out of scope for this file and still open. The mismatched
 * extent is why this entry is EXACT* rather than EXACT.
 *
 * Writing the mask as `~0xffu` rather than building 0xff00 directly is
 * what keeps the mask in the `movs r1, #0xff` / `bics r2, r1` shape the
 * original uses; the equivalent `& 0xff00` immediate has no Thumb
 * encoding and this compiler rematerialises it as `lsls`/`ands` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202744C.c \
 *       --func func_0202744C --addr 0x0202744C --cc 1.1p1 --thumb
 */
#include "../include/Obj00121.h"

typedef unsigned short u16;

void func_0202744C(void *dst)
{
    u16 v = ((struct Obj00121 *)dst)->f48;

    v = (v & ~0xffu) | 5;
    ((struct Obj00121 *)dst)->f48 = v;
}
