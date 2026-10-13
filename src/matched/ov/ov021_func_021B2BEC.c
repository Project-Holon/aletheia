/*
 * function: SCRCMD_SCREENEFFECTS_FindBuildModelEntry
 * address:  0x021B2BEC
 * packet:   pkt_ov021_021B2BEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf filed for lane S20 (blocker of 021B2C08 and friends).
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern int FIELD_BUILDMODEL_GetFirstEntryNearPos(int a, int b, int c);

int SCRCMD_SCREENEFFECTS_FindBuildModelEntry(int a, int b, int c, int d)
{
    int buf[3];

    buf[0] = c << 16;
    buf[1] = 0;
    buf[2] = d << 16;
    return FIELD_BUILDMODEL_GetFirstEntryNearPos(a, b, (int)buf);
}
