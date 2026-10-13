/*
 * function: SCRCMD_SCREENEFFECTS_GetBuildModelMgr
 * address:  0x021B2BD8
 * packet:   pkt_021B2BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);

int SCRCMD_SCREENEFFECTS_GetBuildModelMgr(u32 a)
{
return FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)a))));
}

