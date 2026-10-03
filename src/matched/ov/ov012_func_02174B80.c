/*
 * function: func_02174B80
 * address: 0x02174B80
 * packet: pkt_ov012_02174B80
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(u32);
extern void func_02082D44(void *,void *,u32);
void func_02174B80(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 **)(d + 0x355c);
    if (a == func_0203D1A4((u32)func_020399A8())) return;
    if (w == 0 || *(u32 *)w == 0) return;
    func_02082D44(c, w + 0x18 + a * 44, b);
}
