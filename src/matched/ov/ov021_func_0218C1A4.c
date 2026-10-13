/*
 * function: FIELD_BUILDMODEL_AdvanceAllSlots
 * address:  0x0218C1A4
 * packet:   pkt_ov021_0218C1A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 */

int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

void FIELD_BUILDMODEL_AdvanceAllSlots(int unused, int *s)
{
    int i;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_LoopObjectAnimeFrame((void *)(*s), (unsigned short)i, 0x1000);
}
