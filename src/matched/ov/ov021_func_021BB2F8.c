/*
 * function: FIELD_NOGRID_MAPPER_LoadDataFromArc
 * address:  0x021BB2F8
 * packet:   pkt_ov021_021BB2F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   func_02030734  0x02030734  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FIELD_NOGRID_MAPPER_LoadData  0x021BB278  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DE2D0     0x021DE2D0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
extern void FIELD_NOGRID_MAPPER_LoadData(u32 *a, u16 *b, u32 c);
extern u32 func_020307B0(void *p);
extern int d_021DE2D0;

void FIELD_NOGRID_MAPPER_LoadDataFromArc(u32 a, u32 b, u32 c)
{
    int n = ARC_TOOL_GetMemberSize(0x6d, b);
    void *p = func_02030734((u16)(((u16)c & 0x7FFF) | 0x8000), n, 1, (const char *)&d_021DE2D0, 0xdd);

    ARC_TOOL_ReadMember(p, 0x6d, b);
    FIELD_NOGRID_MAPPER_LoadData((u32 *)a, p, c);
    func_020307B0(p);
}
