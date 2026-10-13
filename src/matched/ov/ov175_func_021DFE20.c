/*
 * function: scCleanupServiceUrl
 * address:  0x021DFE20
 * packet:   pkt_021DFE20
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciGetServiceUrl  0x021DF968  arm
 *   sciGetServiceUrl  0x_021DF968  arm  ov175
 *
 * ARM tail jump to sciGetServiceUrl, the ov175 +0x5c/+0x84 string writer.
 */

extern char *sciGetServiceUrl(void);

void scCleanupServiceUrl(void)
{
    sciGetServiceUrl();
}

