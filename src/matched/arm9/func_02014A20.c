/*
 * function: ZONEDATA_LoadLightTable
 * address:  0x02014A20
 * packet:   pkt_02014808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_TOOL_GetMemberSize       0x020490A8  arm
 *   ARC_TOOL_LoadMember       0x02048F60  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *
 * Load a record table out of an archive sub-file: the sub-file's byte size
 * divided by 0x34 is the record count (unsigned divide, `_u32_div_f`), the
 * count is handed back through a3's slot and the block itself is loaded by
 * ARC_TOOL_LoadMember.  Each 0x34-byte record carries four 6-byte vectors at +0x10
 * (a VecFx16 triple plus a spare halfword) and each is normalized in place
 * before the count is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_LoadLightTable.c \
 *       --func ZONEDATA_LoadLightTable --addr 0x02014A20 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32   ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void *ARC_TOOL_LoadMember(u32 archive, u32 member, u32 heap);
extern u32   _u32_div_f(u32 a, u32 b);
extern void  VEC_Fx16Normalize(void *dest, const void *src);

void *ZONEDATA_LoadLightTable(u32 archive, u32 member, u32 *count_out, u32 heap)
{
    u32 n;
    u32 i;
    u8 *q;
    u8 *p;
    int j;

    n = ARC_TOOL_GetMemberSize(archive, member) / 0x34;
    *count_out = n;
    p = ARC_TOOL_LoadMember(archive, member, heap);
    for (i = 0; i < n; i++) {
        q = p + i * 0x34 + 0x10;
        for (j = 0; j < 4; j++) {
            VEC_Fx16Normalize(q + j * 6, q + j * 6);
        }
    }
    return p;
}
