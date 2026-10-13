/*
 * function: maccmp
 * address:  0x021579BC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Compares three halfwords through advancing cursors; 1 at the first
 * mismatch, 0 when all three agree.
 *
 * symbols:
 *

 */

int maccmp(unsigned short *a, unsigned short *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (*a++ != *b++) return 1;
    }
    return 0;
}


