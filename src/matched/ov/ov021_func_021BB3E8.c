/*
 * function: FIELD_NOGRID_MAPPER_CalcZoneRailLocation
 * address:  0x021BB3E8
 * packet:   pkt_ov021_021BB3E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetSpecialKind  0x02013C9C  thumb
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   func_02030734  0x02030734  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FIELD_RAIL_LOADER_Create  0x0219EF44  thumb  ov021
 *   FIELD_RAIL_LOADER_Load  0x0219EF7C  thumb  ov021
 *   FIELD_RAIL_LOADER_GetSetting  0x0219F018  thumb  ov021
 *   FIELD_RAIL_MakeLineLocation  0x021B7C58  thumb  ov021
 *   FIELD_RAIL_LOADER_Delete  0x0219EF6C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DE2D0     0x021DE2D0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int ZONEDATA_GetSpecialKind(u16 key);
extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
typedef unsigned char  u8;
struct S;
extern u8 *FIELD_RAIL_LOADER_Create(u32 heap);
extern void FIELD_RAIL_LOADER_Load(struct S *p, u32 b, u32 c);
extern u8 *FIELD_RAIL_LOADER_GetSetting(u8 *p);
extern void FIELD_RAIL_MakeLineLocation(u32, u32, u32, u32, u32, u32);
extern void FIELD_RAIL_LOADER_Delete(u8 *p);
extern u32 func_020307B0(void *p);
extern int d_021DE2D0;

void FIELD_NOGRID_MAPPER_CalcZoneRailLocation(u32 *a, u32 b, u16 c, u16 d, u16 e, u32 f, u16 g)
{
    u16 id;
    u16 *p;
    u32 h;

    id = (g & 0x7FFF) | 0x8000;
    p = (u16 *)func_02030734(id, ARC_TOOL_GetMemberSize(0x6d, ZONEDATA_GetSpecialKind(b)), 1, (const char *)&d_021DE2D0, 0x1c9);
    ARC_TOOL_ReadMember(p, 0x6d, ZONEDATA_GetSpecialKind(b));
    h = (u32)FIELD_RAIL_LOADER_Create(id);
    FIELD_RAIL_LOADER_Load((struct S *)h, p[0], id);
    FIELD_RAIL_MakeLineLocation(a[0], (u32)FIELD_RAIL_LOADER_GetSetting((u8 *)h), c, d, e, f);
    FIELD_RAIL_LOADER_Delete((u8 *)h);
    func_020307B0(p);
}
