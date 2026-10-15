/*
 * function: gpDestroy
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
 *   gpiDestroy  0x02186788  arm  ov009
 */

extern void gpiDestroy(void **connection);

void gpDestroy(int **p)
{
    if (p && *p) {
        gpiDestroy((void **)p);
    }
}

