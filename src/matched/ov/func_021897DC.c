/*
 * function: FIELDMAP_ReflectFog
 * address:  0x021897DC
 * packet:   pkt_021897DC
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
 *   FIELD_FOG_Reflect  0x021A0170  thumb  ov021
 *   FIELD_LIGHT_Reflect  0x021A0568  thumb  ov021
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_LIGHT_ApplySlots  0x02048C58  arm
 *   FIELD_G3D_MAPPER_Draw  0x0218CC64  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04887.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Light;
struct LightSlot;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern u32 FIELD_G3D_MAPPER_Draw(u32, u32, u32);
extern void FIELD_FOG_Reflect(u8 *p, u32 a1, u32 a2, u32 a3);
extern void FIELD_LIGHT_Reflect(u8 *p, int force);

int FIELDMAP_ReflectFog(u32 a, u32 b, u32 c, u32 d)
{
FIELD_FOG_Reflect((u8 *)(((struct Obj04887 *)((u8 *)(a)))->f18), b, c, d);
FIELD_LIGHT_Reflect((u8 *)(((struct Obj04887 *)((u8 *)(a)))->f14), 0);
G3D_CAMERA_Reset((struct Light *)(*(u32 *)((u8 *)((a + 164)))));
G3D_LIGHT_ApplySlots((struct LightSlot *)(*(u32 *)((u8 *)((a + 168)))));
return FIELD_G3D_MAPPER_Draw(((struct Obj04887 *)((u8 *)(a)))->f48, *(u32 *)((u8 *)((a + 164))), 0);
}

