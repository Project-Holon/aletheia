/*
 * function: func_02174CB8
 * address: 0x02174CB8
 * packet: pkt_ov012_02174CB8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_021750D8 0x021750D8 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0203D378(void);
extern int func_021750D8(u8 *,u32,u32);
void func_02174CB8(u32 a, u32 b, u8 *c, u8 *d)
{
    u8 *w = *(u8 **)(d + 0x355c);
    if (w == 0 || *(u32 *)w == 0) return;
    if (func_0203D378() == 0) return;
    func_021750D8(w,a,*c);
}
