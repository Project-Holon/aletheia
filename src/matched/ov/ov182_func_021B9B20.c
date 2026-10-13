/*
 * function: func_021B9B20
 * address: 0x021B9B20
 * packet: pkt_ov182_021B9B20
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_021B9840 0x021B9840 thumb ov182
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021B9BE4 0x021B9BE4 data a4
 *   d_021B9BD8 0x021B9BD8 data a4
 *   d_021B9BF0 0x021B9BF0 data a4
 */
typedef unsigned short u16;
extern void G3D_SYSTEM_Init(int,int,int,int,u16,u16,void *);
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const void *,const void *,const void *,u16);
extern void func_021B9840(void);
extern const short d_020A1EB8[];
extern const int d_021B9BE4[],d_021B9BD8[],d_021B9BF0[];
void func_021B9B20(int *p,u16 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021B9840);
    *p=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,d_021B9BE4,d_021B9BD8,d_021B9BF0,heap);
}
