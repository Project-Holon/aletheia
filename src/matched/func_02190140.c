/*
 * function: func_02190140
 * address:  0x02190140
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the block is non-null and all six pointers at +0x10, +8, +0xc,
 * +0x1c, +0x14 and +0x20 are null.
 *
 * symbols:
 *

 */

int func_02190140(char *p)
{
    if (p != 0
        && *(int *)(p + 0x10) == 0
        && *(int *)(p + 8) == 0
        && *(int *)(p + 0xc) == 0
        && *(int *)(p + 0x1c) == 0
        && *(int *)(p + 0x14) == 0
        && *(int *)(p + 0x20) == 0)
        return 1;
    return 0;
}


