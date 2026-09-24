/*
 * function: func_0218592C
 * address:  0x0218592C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the release helper when the pointer and its block are both there.
 *
 * symbols:
 *   func_02186788  0x02186788  arm  ov009
 */

extern void func_02186788(void *p);

void func_0218592C(int **p)
{
    if (p && *p) {
        func_02186788(p);
    }
}

