/*
 * function: func_02167848
 * address:  0x02167848
 * packet:   pkt_02167848
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +005C. Coherent
 * Thumb code in ov010 (ARM data in ov009). The byte shape is reproduced
 * (block ldm/stm for the first two words, then the scalar stores) but mwcc
 * evaluates the 64-bit RHS address before the destination and picks different
 * registers; see docs/notes/ov019_func_0217FF78.c.txt. Left as the documented
 * near miss while func_0217FF78 stays MATCH on this one site.
 *
 * wave-8 re-check: the region/ISA hint is confirmed correct (`thumb ov010`,
 * ov009 holds ARM data at the address), the row is size-exact at 36 bytes and
 * the instruction sequence is the original's, so this remains an allocator
 * coin-flip (dst r3/r4/r5 vs r0/r1/r4) and not a witness or hint problem.
 * Four more spellings (u16/s16 index, Pair lvalue, Dst/Src struct types) all
 * emit the same wrong allocation.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned long long u64;

void func_02167848(char *a0, int a1, char *a2)
{
    *(u64 *)(a0 + a1 * 0x1C + 8) = *(u64 *)(a2 + 4);
    *(u32 *)(a0 + a1 * 0x1C + 0x10) = *(u32 *)(a2 + 0xC);
    *(u16 *)(a0 + a1 * 0x1C + 0x18) = *(u16 *)(a2 + 0x10);
    *(u32 *)(a0 + a1 * 0x1C + 0x14) = *(u32 *)(a2 + 0);
}
