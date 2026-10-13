/*
 * function: FIELDMAP_DeleteG3dResources
 * address:  0x021890C8
 * packet:   pkt_021890C8
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
 *   G3D_LIGHT_DeleteSlots  0x02048C4C  arm
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   BILLBOARD_ACT_Delete  0x0204FFFC  arm
 *   FIELD_G3DOBJ_Delete  0x021C6400  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct BbActSys;
extern u32 G3D_CAMERA_Delete(void *ptr);
extern u32 G3D_LIGHT_DeleteSlots(u32, u32, u32, u32);
extern void BILLBOARD_ACT_Delete(struct BbActSys *o);
extern u32 FIELD_G3DOBJ_Delete(u32);

int FIELDMAP_DeleteG3dResources(u32 a, u32 b, u32 c, u32 d)
{
G3D_LIGHT_DeleteSlots(*(u32 *)((u8 *)((a + 168))), b, c, d);
G3D_CAMERA_Delete((void *)(*(u32 *)((u8 *)((a + 164)))));
BILLBOARD_ACT_Delete((struct BbActSys *)(*(u32 *)((u8 *)((a + 176)))));
BILLBOARD_ACT_Delete((struct BbActSys *)(*(u32 *)((u8 *)((a + 180)))));
BILLBOARD_ACT_Delete((struct BbActSys *)(*(u32 *)((u8 *)((a + 184)))));
return FIELD_G3DOBJ_Delete(*(u32 *)((u8 *)(a) + ((19 << 4))));
}

