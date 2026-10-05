/*
 * function: func_02200188
 * address: 0x02200188
 * packet: pkt_ov186_02200188
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * residual: DIFF 18 of 160 B, a 3-register rotation. Original: table r4, loop-1 counter
 *   and filled r5, start/loop-2 counter r6, end r7. Compiled: start r4, table r5, counters r6.
 *   Size, spill slots and all other bytes match.
 * note 2026-10-05 (wave P15 D4): callees re-derived (0200D064 returns u32, 02030734 returns
 *   a pointer, 02082BCC void, no change). Twin search: grep func_0200D064 over src/matched/ov
 *   (10 files), only ov186 0220014C shares the d_02200C94 walk; no twin has all three callees.
 *   Tried, all 18 B unless noted: static inline count helper for loop 1 (28); index and
 *   statement order of the two range loads (31 to 38); table non-const; loop-1 counter as
 *   separate u32 i; separate i and j counters; i reused as filled; local copy of table;
 *   u32 count/filled; end u16 (33), start u16 (52); heap u32 (78); element id local (122).
 *   Pragmas: opt_lifetimes off gives 12 B (start right, table and counter swapped); others
 *   unchanged (common_subs 68); lifetimes off combined with separate counters stays 18.
 *   Idioms read: a-dead-parameter-reused-as-the-index-rotates-the-loop-registers,
 *   a-named-per-element-pointer-settles-thumb-loop-register-colours,
 *   a-pos-accumulation-settles-a-callee-saved-rotation,
 *   a-separate-index-local-per-loop-reorders-spill-slots,
 *   a-long-loop-counter-keeps-its-copy-of-a-parameter-out-of-the-entry-guard.
 *   Older note (wave 82 R8) in docs/notes/pkt_ov186_02200188.c.txt lists further tries.
 * symbols:
 *   func_0200D064 0x0200D064 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02200C94 0x02200C94 data a2
 *   d_02200D9C 0x02200D9C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0200D064(void *, u16);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u8, u32);
extern const u16 d_02200C94[];
extern const char d_02200D9C[];
u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap)
{
    u32 end, start;
    u16 *dst;
    int filled;
    int count, bytes;
    end = d_02200C94[index + 1];
    count = 0;
    start = d_02200C94[index];
    for (filled = start; filled < end; filled++) if (func_0200D064(p, table[filled])) count++;
    bytes = count * 2;
    dst = func_02030734(heap, bytes, 0, d_02200D9C, 0x3c3);
    filled = 0;
    func_02082BCC(dst, 0, bytes);
    for (; start < end; start++) if (func_0200D064(p, table[start])) dst[filled++] = table[start];
    if (out) *out = filled;
    return dst;
}
