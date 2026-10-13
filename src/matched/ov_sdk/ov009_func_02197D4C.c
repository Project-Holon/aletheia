/*
 * function: gti2ConnectionFree
 * address:  0x02197D4C
 * packet:   pkt_ov009_02197D4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gti2ConnectionCleanup        0x02195A30  arm
*/

extern void gti2ConnectionCleanup(void *connection);

static void gti2ConnectionFree(void **elem)
{
    gti2ConnectionCleanup(*elem);
}
