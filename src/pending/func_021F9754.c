/*
 * function: func_021F9754
 * address:  0x021F9754
 * packet:   pkt_021F9754
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  5 bytes differ; the original keeps the p+i*4 base in r1 and the
 *   constant 1 in r3, this compiler swaps them (r3 base, r1 constant) in every
 *   spelling tried (int index reuse, pointer local, single expression).
 *
 * Re-verified (DIFF fixer): also tried inlining both stores with no local,
 * `int *q = (int *)(p + i*4)` with `q[0xFC/4]`/`q[0x10C/4]` subscripts, and
 * `p += i*4`; all five bytes, always the r1/r3 swap.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021F9754(char *p, int i, int v)
{
    char *q = p + i * 4;
    *(int *)(q + 0xFC) = 1;
    *(int *)(q + 0x10C) = v;
}
