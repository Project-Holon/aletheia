/*
 * function: FIELD_SOUND_SYSTEM_GetZoneBgm
 * address:  0x02029E64
 * packet:   pkt_02029E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ZONEDATA_GetBgmId  0x02013BDC  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 ZONEDATA_GetBgmId(u32 id, u32 which);

u32 FIELD_SOUND_SYSTEM_GetZoneBgm(void *unused, u32 id, u32 which)
{
    return ZONEDATA_GetBgmId((u16)id, which);
}
