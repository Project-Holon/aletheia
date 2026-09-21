/*
 * unit:     no
 * function: sub_0202E448
 * address:  0x0202E448
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202E448_Table  0x020A02A8  data
 *
 * Byte-correct. A linear search of a seven-entry halfword table: each
 * entry packs a 10-bit key and a 6-bit value, and the function answers
 * the value of the first entry whose key matches, or 0x19. The two
 * `lsls`/`lsrs` pairs with amounts 22 and 16/26 are the two bitfields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the
 * prologue is `push {r3, r4}` with no lr, because the function calls
 * nothing, which is also why `disasm.py` gives it no label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Why it is capped: the pool word at 0x0202E470 is the only occurrence of
 * 0x020A02A8 anywhere in the image, so the `literal` class discards its
 * only witness; the address is data in bss-adjacent rodata and so will
 * never carry a `func_` label, and the `matched` class deliberately does
 * not cover data. No cut helps, because the range cannot be made smaller
 * than this one function and the pool word is part of it. Closes when a
 * second reference to the table appears, which means matching whatever
 * else reads it.
 *
 * src/matched/sub_0202E43C.c is the function immediately before it, kept
 * out of this file for exactly that reason.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0202E448.c \
 *       --func sub_0202E448 --addr 0x0202E448 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent0202E448 {
    u16 id  : 10;
    u16 val : 6;
};

extern const struct Ent0202E448 sub_0202E448_Table[];

u32 sub_0202E448(u32 id)
{
    u32 i;

    for (i = 0; i < 7; i++) {
        if (id == sub_0202E448_Table[i].id) {
            return sub_0202E448_Table[i].val;
        }
    }
    return 0x19;
}
