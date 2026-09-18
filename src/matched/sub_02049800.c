/*
 * unit:     no
 * function: sub_02049800
 * address:  0x02049800
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_0204982C  0x0204982C  arm
 *
 * Byte-correct, capped at MATCH. Blocked on: func_0204982C (0x0204982C) has
 * exactly one branch reference in the whole image, the `bl` at 0x02049824
 * inside this function, and it begins at the first byte past this function's
 * own extent (02049800..0204982C), so no evidence class witnesses it. This
 * used to print EXACT anyway (`compare()` claimed EXACT from literal byte
 * equality alone, without checking that every relocation field had actually
 * been resolved), because the PC24 field's compiler-emitted displacement to
 * the immediately-following address happens to coincide with the image's
 * bytes by plain adjacency, not by attestation; `compare()` now requires
 * `fb.mask` to be entirely hard before claiming EXACT, so this correctly
 * reports MATCH. It graduates for real only once 0x0204982C has an EXACT
 * entry of its own: src/pending/sub_0204982C.c is the C for it, stuck at
 * MATCH on the unattestable data address 0x020A135C. func_0204A380 resolves
 * normally (label, and src/matched/func_0204A380.c).
 *
 * A seven-argument front end that loads an archive member and hands the
 * buffer to the flush-and-dispatch worker; the flag word is passed straight
 * through as a halfword rather than having its top bit forced on, which is
 * what distinguishes this family member from src/matched/sub_02049740.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02049800.c \
 *       --func sub_02049800 --addr 0x02049800 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0204A380(u32 a0, u32 a1, u32 a2, u16 a3);
extern u32 func_0204982C(void *buf, u32 kind, u32 a2, u32 size);

u32 sub_02049800(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    return func_0204982C(func_0204A380(a0, a1, a5, a6), a2, a3, a4);
}
