/*
 * function: POKETRADE_SAVE_Free3DLightSet
 * address: 0x021E2B68
 * packet: pkt_ov119_021E2B68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gLightSetHandle 0x021F4560 data
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 */
extern void G3D_LIGHT_DeleteSlots(void *);
extern void *gLightSetHandle;
void POKETRADE_SAVE_Free3DLightSet(void)
{
    G3D_LIGHT_DeleteSlots(gLightSetHandle);
}
