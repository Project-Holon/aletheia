/*
 * function: DWCi_GdbShutdownGsCore
 * address:  0x021E191C
 * packet:   pkt_021E191C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsCoreShutdown  0x0217CD94  arm  ov009
 *   gsCoreThink  0x0217CCCC  arm  ov009
 *   gsCoreIsShutdown  0x0217CE1C  arm  ov009
 *
 * Starts the ov009 transaction, releases the null handle, then checks
 *  *  the status: unless 0x0217CE1C reports 2 the null handle is released a
 *  *  second time.
 */

extern void gsCoreShutdown(void);
extern void gsCoreThink(unsigned int theMS);
extern int  gsCoreIsShutdown(void);

void DWCi_GdbShutdownGsCore(void)
{
    gsCoreShutdown();
    gsCoreThink(0);
    if (gsCoreIsShutdown() != 2)
        gsCoreThink(0);
}

