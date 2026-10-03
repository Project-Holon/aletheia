/*
 * function: func_021B66FC
 * address: 0x021B66FC
 * packet: pkt_ov067_021B66FC
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203FB44's low/high halfword arguments preserve the explicit
 * caller narrowing; the first argument follows its own u32 definition.
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204AFD8(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02082BCC(void *, u32, u32);
void func_021B66FC(u32 *p)
{
    func_0204AFD8(p[2]);
    func_0204A8D4(p[1]);
    func_0204ADA4(p[0]);
    func_0203FB44(p[3], (u16)p[4], (u16)(p[4] >> 16));
    func_02082BCC(p, 0, 0x14);
}
