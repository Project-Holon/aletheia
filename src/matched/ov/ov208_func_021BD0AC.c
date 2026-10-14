/*
 * function: ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera
 * address: 0x021BD0AC
 * packet: pkt_ov208_021BD0AC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   ZUKAN_DETAIL_GRAPHIC_Init3dSettings 0x021BCD68 thumb ov208
 *   d_021C8114 0x021C8114 data a4
 *   g_020A1EB8 0x020A1EB8 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {int x,y,z;} Vec3;
extern const Vec3 d_021C8114[];
extern const char g_020A1EB8[];
extern void ZUKAN_DETAIL_GRAPHIC_Init3dSettings(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,const Vec3 *,const Vec3 *,const Vec3 *,u16);
void ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(u32 **p,u16 heap)
{
    G3D_SYSTEM_Init(0,1,0,2,0,heap,ZUKAN_DETAIL_GRAPHIC_Init3dSettings);
    *p=G3D_CAMERA_Create(0,*(const short *)(g_020A1EB8+12),*(const short *)(g_020A1EB8+14),0x1555,0,0x107c20,0x400000,0,&d_021C8114[1],&d_021C8114[0],&d_021C8114[2],heap);
}
