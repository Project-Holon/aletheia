/*
 * function: COMM_BTL_DEMO_GRAPHIC_InitG3d
 * address: 0x021BADC8
 * packet: pkt_ov213_021BADC8
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const ROM table orders signed halfword loads and pool entries.
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   COMM_BTL_DEMO_MAIN_Init3dSystem 0x021BAABC thumb ov213
 *   d_021BB158 0x021BB158 data a4
 *   d_021BB164 0x021BB164 data a4
 *   d_021BB170 0x021BB170 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 * width: both heap externs widened: 021BADD6/021BAE1C store full r1.
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec3;
extern const Vec3 d_021BB158;
extern Vec3 d_021BB164,d_021BB170;
extern const unsigned char d_020A1EB8[];
extern void COMM_BTL_DEMO_MAIN_Init3dSystem(void);
extern void G3D_SYSTEM_Init(u32 a,u32 b,u32 c,u32 d,u16 fifo,unsigned heap,void (*setup)(void));
extern u32 *G3D_CAMERA_Create(u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h,Vec3 *i,Vec3 *j,Vec3 *k,unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_InitG3d(u32 **p,unsigned heap)
{
    Vec3 copy;
    G3D_SYSTEM_Init(0,1,0,1,0,heap,COMM_BTL_DEMO_MAIN_Init3dSystem);
    copy=d_021BB158;
    *p=G3D_CAMERA_Create(0,*(const short *)(d_020A1EB8+12),*(const short *)(d_020A1EB8+14),0x1555,0,0x1000,0x400000,0,&d_021BB170,&copy,&d_021BB164,heap);
}
