/*
 * function: ZONEDATA_IsZoneInTableDFEC
 * address:  0x02013DE0
 * packet:   pkt_02013DE0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_IsZoneInTable  0x02013B10  thumb
 *   d_0209DFEC     0x0209DFEC  data  a4
 *
 * Unlabelled Thumb leaf after ZONEDATA_IsZoneInTableDFC0: a tail call
 * to ZONEDATA_IsZoneInTable with a fixed table and count. Filed as the witness for
 * the ov020 caller FIELD_WFBC_DATA_LOCAL_AdvanceDays (wave D4 lane 12).
 */

extern const int d_0209DFEC[];
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
u32 ZONEDATA_IsZoneInTable(u32 id, const u16 *table, s32 count);

int ZONEDATA_IsZoneInTableDFEC(u16 a0)
{
    return ZONEDATA_IsZoneInTable(a0, (const u16 *)d_0209DFEC, 9);
}
