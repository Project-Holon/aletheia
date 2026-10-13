/*
 * function: RefStringFree
 * address:  0x0219DF54
 * packet:   pkt_ov009_0219DF54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsifree                      0x0217EAE0  arm
*/

extern void gsifree(void *ptr);

void RefStringFree(void *elem)
{
    gsifree(*(void **)elem);
}
