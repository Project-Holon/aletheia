/*
 * function: ISS_CITY_UNIT_FindStepZ
 * address:  0x0202B104
 * packet:   pkt_0202AF74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ISS_CITY_UNIT_GetCenterZ  0x0202B174  thumb
 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 ISS_CITY_UNIT_GetCenterZ(u32 *a0);

u32 ISS_CITY_UNIT_FindStepZ(u8 *a0, s32 *a1)
{
    s32 i;
    s32 v = a1[2] >> 12;
    s32 d = v - ISS_CITY_UNIT_GetCenterZ((u32 *)a0);

    if (d < 0) d = -d;
    for (i = 0; i < 6; i++) {
        if ((a0[i + 0x22] << 4) <= d) return (u8)i;
    }
    return 0;
}
