/*
 * function: func_02174C90
 * address: 0x02174C90
 * packet: pkt_ov012_02174C90
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
void func_02174C90(u32 a)
{
    func_0203D3F8(func_020399A8(),255,0x1503,20,a,0,1,1);
}
