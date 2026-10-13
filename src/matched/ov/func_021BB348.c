/*
 * function: FIELD_NOGRID_MAPPER_ReleaseData
 * address:  0x021BB348
 * packet:   pkt_021BB348
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
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb  ov021
 *   FIELD_RAIL_ClearSetting  0x021B7954  thumb  ov021
 *   FIELD_RAIL_LOADER_Unload  0x0219EFFC  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Unload  0x021AB868  thumb  ov021
 *   RAIL_ATTR_Release  0x021BB11C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01663.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_RAIL_LOADER_Unload(u32 a);
extern u32 FLD_SCENEAREA_ClearData(u32);
extern u32 FLD_SCENEAREA_LOADER_Unload(u32);
extern u32 FIELD_RAIL_ClearSetting(u32);
extern u32 RAIL_ATTR_Release(u32);

int FIELD_NOGRID_MAPPER_ReleaseData(u32 a)
{
FLD_SCENEAREA_ClearData(((struct Obj01663 *)((u8 *)(a)))->fC);
FIELD_RAIL_ClearSetting(((struct Obj01663 *)((u8 *)(a)))->f0);
FIELD_RAIL_LOADER_Unload(((struct Obj01663 *)((u8 *)(a)))->f4);
FLD_SCENEAREA_LOADER_Unload(((struct Obj01663 *)((u8 *)(a)))->f10);
return RAIL_ATTR_Release(((struct Obj01663 *)((u8 *)(a)))->f8);
}

