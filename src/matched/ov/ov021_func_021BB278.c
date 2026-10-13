/*
 * function: FIELD_NOGRID_MAPPER_LoadData
 * address:  0x021BB278
 * packet:   pkt_ov021_021BB278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_NOGRID_MAPPER_ReleaseData  0x021BB348  thumb  ov021
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   FIELD_RAIL_LOADER_Load  0x0219EF7C  thumb  ov021
 *   FIELD_RAIL_LOADER_GetSetting  0x0219F018  thumb  ov021
 *   FIELD_RAIL_SetSetting  0x021B7934  thumb  ov021
 *   RAIL_ATTR_Load  0x021BB0B4  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Load  0x021AB840  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecs  0x021AB880  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecCount  0x021AB884  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetCallbacks  0x021AB888  thumb  ov021
 *   FLD_SCENEAREA_SetData  0x021AB634  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int FIELD_NOGRID_MAPPER_ReleaseData(u32 a);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
typedef unsigned char  u8;
struct S;
extern void FIELD_RAIL_LOADER_Load(struct S *p, u32 b, u32 c);
extern u8 *FIELD_RAIL_LOADER_GetSetting(u8 *p);
extern int FIELD_RAIL_SetSetting(u32 a, u32 b);
extern void RAIL_ATTR_Load(u32 *a, u32 b, u32 c);
extern void FLD_SCENEAREA_LOADER_Load(u32, int, u32, u16);
extern u32 FLD_SCENEAREA_LOADER_GetRecs(u8 *p);
extern u32 FLD_SCENEAREA_LOADER_GetRecCount(u8 *p);
extern u32 FLD_SCENEAREA_LOADER_GetCallbacks(u32);
extern void FLD_SCENEAREA_SetData(u32, u32, u32, u32);

void FIELD_NOGRID_MAPPER_LoadData(u32 *a, u16 *b, u32 c)
{
    FIELD_NOGRID_MAPPER_ReleaseData((u32)a);
    if (b[0] != 0xFFFF) {
        u32 n = ARC_TOOL_GetArchiveFileCount(0x4f);

        FIELD_RAIL_LOADER_Load((struct S *)a[1], b[0], c);
        FIELD_RAIL_SetSetting(a[0], (u32)FIELD_RAIL_LOADER_GetSetting((u8 *)a[1]));
        RAIL_ATTR_Load((u32 *)a[2], b[0] + (n >> 1), c);
    }
    if (b[1] != 0xFFFF) {
        u32 t, u, v;

        FLD_SCENEAREA_LOADER_Load(a[4], 0, b[1], c);
        t = FLD_SCENEAREA_LOADER_GetRecs((u8 *)a[4]);
        u = FLD_SCENEAREA_LOADER_GetRecCount((u8 *)a[4]);
        v = FLD_SCENEAREA_LOADER_GetCallbacks(a[4]);
        FLD_SCENEAREA_SetData(a[3], t, u, v);
    }
}
