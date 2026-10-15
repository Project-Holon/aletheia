/*
 * function: gpiFreeMessage
 * address:  0x0218F134
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Releases the pointed-to block and clears the pointer.
 *
 * symbols:
 *   gsifree  0x0217EAE0  arm

 */

extern void gsifree(void *p);

void gpiFreeMessage(void **p)
{
    gsifree(*p);
    *p = 0;
}

