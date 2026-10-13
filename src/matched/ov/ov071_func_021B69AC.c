/*
 * function: MONOLITH_TOOL_LoadSlotRecords
 * address:  0x021B69AC
 * packet:   pkt_ov071_021B69AC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When b[0x3D] is set, copies six 24-byte records from the table
 * ARC_TOOL_LoadMember(0x25, 0, 0x61) into a+0x60, indexed by b[4..9] (an index
 * past ARC_TOOL_GetMemberSize's count reads record 0), then frees the table.
 * The loop counter is enum-typed: with an int counter mwcc knows it is zero
 * at the loop and drops the rotation's entry guard (cmp r5,#6; bge), 4 bytes
 * short; an enum-typed counter is not folded (see
 * an-enum-type-keeps-values-out-of-constant-folding.md).
 * The listing's extent includes 2 bytes of alignment padding (EXACT*).
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

struct E24 {
    int w[6];
};

extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern u32 func_020307B0(void *p);

void MONOLITH_TOOL_LoadSlotRecords(u8 *a, u8 *b)
{
    struct E24 *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (b[0x3d] != 0) {
        tbl = ARC_TOOL_LoadMember(0x25, 0, 0x61);
        n = ARC_TOOL_GetMemberSize(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = b[4 + i];
            if (idx >= n) {
                idx = 0;
            }
            *(struct E24 *)(a + 0x60 + i * 24) = tbl[idx];
        }
        func_020307B0(tbl);
    }
}
