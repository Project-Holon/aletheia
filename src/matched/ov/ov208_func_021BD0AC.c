/*
 * function: func_021BD0AC
 * address: 0x021BD0AC
 * packet: pkt_ov208_021BD0AC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021BCD68 0x021BCD68 thumb ov208
 *   d_021C8114 0x021C8114 data a4
 *   g_020A1EB8 0x020A1EB8 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {int x,y,z;} Vec3;
extern const Vec3 d_021C8114[];
extern const char g_020A1EB8[];
extern void func_021BCD68(void);
extern void func_02046440(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,const Vec3 *,const Vec3 *,const Vec3 *,u16);
void func_021BD0AC(u32 **p,u16 heap)
{
    func_02046440(0,1,0,2,0,heap,func_021BCD68);
    *p=func_02048A24(0,*(const short *)(g_020A1EB8+12),*(const short *)(g_020A1EB8+14),0x1555,0,0x107c20,0x400000,0,&d_021C8114[1],&d_021C8114[0],&d_021C8114[2],heap);
}
