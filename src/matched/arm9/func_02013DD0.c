/*
 * function: ZONEDATA_IsZoneInTableDFC0
 * address:  0x02013DD0
 * packet:   pkt_02013DD0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZONEDATA_IsZoneInTable  0x02013B10  thumb
 *   d_0209DFC0     0x0209DFC0  data  a4
 *
 * Unlabelled Thumb leaf inside ZONEDATA_IsZoneGroup118To120's listing extent: a tail call
 * to ZONEDATA_IsZoneInTable with a fixed table and count. Filed as the witness for
 * the ov021 and ov018 callers.
 */

extern const int d_0209DFC0[];
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
u32 ZONEDATA_IsZoneInTable(u32 id, const u16 *table, s32 count);

int ZONEDATA_IsZoneInTableDFC0(int a0)
{
    return ZONEDATA_IsZoneInTable(a0, (const u16 *)d_0209DFC0, 4);
}
