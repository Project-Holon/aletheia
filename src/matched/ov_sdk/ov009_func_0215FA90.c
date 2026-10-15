/*
 * function: SOC_Cleanup
 * address:  0x0215FA90
 * packet:   pkt_ov009_0215F8FC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    defined in src/game/ov009/unit_0215F650.c without a verification
 *           entry.
 *
 * symbols:
 *   SOCL_Cleanup  0x0215EBF0  arm
 */

extern int SOCL_Cleanup(void);

int SOC_Cleanup(void)
{
    return SOCL_Cleanup();
}
