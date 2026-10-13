/*
 * function: WEATHER_ReleaseBillboardVramTask
 * address:  0x021A1C1C
 * packet:   pkt_ov021_021A1C1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_3DBG_ReleaseBillboardTextureVram  0x021A1670  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
void FIELD_3DBG_ReleaseBillboardTextureVram(u8 *p);

void WEATHER_ReleaseBillboardVramTask(int a, u32 *p)
{
    int i;

    for (i = 0; i < 2; i++)
        FIELD_3DBG_ReleaseBillboardTextureVram((u8 *)p[i]);
}
