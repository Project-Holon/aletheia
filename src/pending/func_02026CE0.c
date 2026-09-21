/*
 * unit:     no
 * function: func_02026CE0
 * address:  0x02026CE0
 * packet:   pkt_02026CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Clears bit `n` of the 32-bit flag word at +0xba4 of the object the
 * global pointer at 0x02021440 names.
 *
 * BLOCKER: every concrete byte matches (MATCH*), but the single ABS32 to
 * the data pointer 0x02021440 has no attestation.  No evidence class
 * reaches it: it is plain data, so `label` and `veneer` do not apply, it
 * is not in layout/runtime_arm9.txt, and the word 0x02021440 appears in
 * no other literal pool anywhere in the image (checked across asm/), so
 * the `literal` class has nothing to offer either.  The only witness is
 * this function's own pool word, which is inside the compared range.
 * Unsticking this needs a second, already-EXACT reader of the same
 * global.  `--suggest-split` cannot help: the range is one function.
 *
 * symbols:
 *   g_02021440  0x02021440  data
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx {
    u8  pad_0000[0xba4];
    u32 flags;
};

extern struct Ctx *g_02021440;

void func_02026CE0(u32 n)
{
    g_02021440->flags = ((1 << n) ^ 0xffffffff) & g_02021440->flags;
}
