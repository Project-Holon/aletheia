/*
 * function: sakeiFreeRequest
 * address:  0x021DD604
 * packet:   pkt_021DD604
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsifree  0x0217EAE0  arm  ov009
 *   gsifree  0x_0217EAE0  arm  ov009
 *
 * Second ARM tail jump to 0x0217EAE0 (ov009), the pair partner of
 *  *  sakeShutdown on the +0x1c path.
 */

extern void gsifree(void);

void sakeiFreeRequest(void *request)
{
    gsifree();
}

