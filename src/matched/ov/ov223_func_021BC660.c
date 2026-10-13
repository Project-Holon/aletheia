/*
 * function: func_021BC660
 * address: 0x021BC660
 * packet: pkt_ov223_021BC660
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC34C 0x021BC34C thumb ov223
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_021BC928 0x021BC928 data a4
 *   d_021BC91C 0x021BC91C data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 */
extern const short d_020A1EB8[];
extern int d_021BC91C[],d_021BC910[],d_021BC928[];
extern void func_021BC34C(void);
extern void G3D_SYSTEM_Init(int,int,int,int,int,unsigned short,void (*)(void));
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const int *,const int *,const int *,unsigned short);
void func_021BC660(int *p,unsigned short heap)
{
    G3D_SYSTEM_Init(0,1,0,1,4096,heap,func_021BC34C);
    *p=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,0x400000,0,d_021BC91C,d_021BC910,d_021BC928,heap);
}
