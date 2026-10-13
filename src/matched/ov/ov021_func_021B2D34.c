/*
 * function: SCRCMD_SCREENEFFECTS_CreateBuildModelNode
 * address:  0x021B2D34
 * packet:   pkt_ov021_021B2D34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_CreateNodeNearPos  0x0218C7D8  thumb  ov021
 *   FIELD_BUILDMODEL_GetNodeHandle  0x0218BACC  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_CreateNodeNearPos(void *p, int b, int c);
extern int FIELD_BUILDMODEL_GetNodeHandle(int a, int b);

int SCRCMD_SCREENEFFECTS_CreateBuildModelNode(int a, int b)
{
    unsigned short *out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    int f = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int h;
    int buf[3];

    h = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))));
    buf[0] = x << 16;
    buf[1] = 0;
    buf[2] = y << 16;
    *out = FIELD_BUILDMODEL_GetNodeHandle(h, FIELD_BUILDMODEL_CreateNodeNearPos((void *)h, f, (int)buf));
    return 0;
}
