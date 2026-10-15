/*
 * function: MYSTERY_DATA_Unload
 * address:  0x0200A3D0
 * packet:   pkt_0200A3D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  0x021DFDB8 is an unlabelled ov228 leaf, a
 *           one-argument tail call to the ARM heap free func_020307B0, now
 *           matched in src/matched/SAVE_OUTSIDE_Free.c (shard ov228/pkt_021DFC20);
 *           the ov228 hint below makes the site `matched, overlay`.
 * symbols:
 *   ov_abs_e4      0x000000E4  data
 *   SAVE_OUTSIDE_Free  0x021DFDB8  thumb  ov228
 *   func_02034A5C  0x02034A5C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Third pass, lane 1: this row was DIFF for two passes and is now byte-correct.
 * The residue was never a codegen difference.  The original's second call is
 *
 *   0200A3E4  04 48        ldr r0, [pc, #0x10]
 *   0200A3E6  2a f0 3a eb  blx #0x2034a5c
 *   ...
 *   0200A3F8  e4 00 00 00  0x000000E4
 *
 * a small constant loaded from the pool where `func_02034A5C(0xe4)` gives
 * `movs r0, #0xe4`.  That is the reading of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md: a pool
 * word holding a value too small to be an address is an `R_ARM_ABS32` against
 * an absolute symbol, i.e. 0xE4 is a linker-defined id, and declaring it and
 * passing it reproduces the original's pool word and all 44 bytes.  The
 * site resolves as `literal x2` (two other pool words in the image hold
 * 0x000000E4, e.g. 0x02007070), which is what confirms the reading.
 * Five numeric spellings were tried and all five give `movs`:
 * `0xe4`, `(u32)0xe4`, a macro, a `static const u32`, and a file-scope
 * `const u32`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/MYSTERY_DATA_Unload.c \
 *       --func MYSTERY_DATA_Unload --addr 0x0200A3D0 --cc 1.1p1 --thumb
 */
#include "../include/Obj11228.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8   ov_abs_e4[];
extern void SAVE_OUTSIDE_Free(void *v);
extern void func_02034A5C(int p);
extern void MI_CpuFill8(void *p, int c, u32 n);

void MYSTERY_DATA_Unload(void *obj)
{
    switch (((struct Obj11228 *)obj)->f4) {
    case 0:
        SAVE_OUTSIDE_Free((void *)((struct Obj11228 *)obj)->f8);
        func_02034A5C((int)ov_abs_e4);
        break;
    case 1:
        break;
    }
    MI_CpuFill8(obj, 0, 0xc);
}
