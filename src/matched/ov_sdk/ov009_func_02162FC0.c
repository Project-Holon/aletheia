/*
 * function: char_from_long
 * address:  0x02162FC0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call to MI_CpuCopy8 with its first two arguments swapped.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm  arm9

 */

extern void MI_CpuCopy8(void *a, void *b, int n);

static void char_from_long(void *a, void *b, int n)
{
    MI_CpuCopy8(b, a, n);
}

