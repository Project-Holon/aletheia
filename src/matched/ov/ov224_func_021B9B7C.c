/*
 * function: SUBWAY_MAP_GRAPHIC_CreateCamera
 * address: 0x021B9B7C
 * packet: pkt_ov224_021B9B7C
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The read-only cfg table is const: removing const delayed signed-halfword
 * loads past outgoing argument stores (108 bytes,19 concrete bytes out).
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   SUBWAY_MAP_GRAPHIC_Setup3d 0x021B989C thumb ov224
 *   vecA 0x021B9C3C data
 *   vecB 0x021B9C30 data
 *   vecC 0x021B9C48 data
 *   cfg 0x020A1EB8 data
 */
typedef unsigned int u32;
typedef signed short s16;
extern const s16 cfg[];
extern u32 vecA[],vecB[],vecC[];
extern void SUBWAY_MAP_GRAPHIC_Setup3d(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,unsigned short,u32,void(*)(void));
extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,void *,void *,void *,u32);
void SUBWAY_MAP_GRAPHIC_CreateCamera(void **p,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,SUBWAY_MAP_GRAPHIC_Setup3d);
    *p = G3D_CAMERA_Create(0,cfg[6],cfg[7],0x1555,0,0x1000,0x400000,0,
        vecA,vecB,vecC,heap);
}
