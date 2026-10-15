/*
 * function: gsiCancelResolvingHostname
 * address:  0x0217F1C0
 * packet:   pkt_ov009_0217F150
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    defined in src/game/ov009/unit_0217F130.c without a verification
 *           entry.
 *
 * symbols:
 *   gsifree  0x0217EAE0  arm
 */

extern void gsifree(void *p);

void gsiCancelResolvingHostname(void *p)
{
    gsifree(p);
}
