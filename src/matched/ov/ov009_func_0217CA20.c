/*
 * function: gsiCoreGetManager
 * address:  0x0217CA20
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Address of the module state object.
 *
 * symbols:
 *   gGSCoreManager  0x021ACFD4  data
 */

extern char gGSCoreManager[];

void *gsiCoreGetManager(void)
{
    return gGSCoreManager;
}

