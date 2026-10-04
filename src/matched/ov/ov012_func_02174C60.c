/*
 * function: func_02174C60
 * address: 0x02174C60
 * packet: pkt_ov012_02174C60
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021751B4 0x021751B4 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern void func_021751B4(u8 *,u32,void *);
void func_02174C60(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 **)(d + 0x355c);
    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) return;
    if (w == 0 || *(u32 *)w == 0) return;
    func_021751B4(w,a,c);
}
