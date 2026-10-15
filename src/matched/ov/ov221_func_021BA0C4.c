/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera
 * address: 0x021BA0C4
 * packet: pkt_ov221_021BA0C4
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const coordinate table fixes 19 scheduling bytes; heap widened at both callees, original untruncated.
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   CHIHOU_ZUKAN_AWARD_Setup3d 0x021B9DD4 thumb ov221
 *   d_021BA1B0 0x021BA1B0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 */

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec3;
extern Vec3 d_021BA1B0[3];
extern const s16 d_020A1EB8[];
extern void CHIHOU_ZUKAN_AWARD_Setup3d(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void(*)(void));
extern u32* G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec3*,Vec3*,Vec3*,u32);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32**p,u32 heap)
{
 G3D_SYSTEM_Init(0,1,0,1,0,heap,CHIHOU_ZUKAN_AWARD_Setup3d);
 *p=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&d_021BA1B0[1],&d_021BA1B0[0],&d_021BA1B0[2],heap);
}
