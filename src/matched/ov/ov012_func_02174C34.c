/*
 * function: func_02174C34
 * address: 0x02174C34
 * packet: pkt_ov012_02174C34
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
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
void func_02174C34(u32 a)
{
    func_0203D3F8((u32)func_020399A8(),255,0x1502,0x678,a,1,0,1);
}
