/*
 * function: GIMMICK_OBJ_ELBOARD_CheckEntryGPower
 * address:  0x021F4E3C
 * packet:   pkt_021F4E3C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 GPOWER_GetSpecialPowerId(void);

int GIMMICK_OBJ_ELBOARD_CheckEntryGPower(int *p)
{
    if (p[0] == 0)
        return 1;
    if (p[0] == GPOWER_GetSpecialPowerId())
        return 1;
    return 0;
}
