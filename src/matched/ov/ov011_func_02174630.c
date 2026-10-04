/*
 * function: func_02174630
 * address: 0x02174630
 * packet: pkt_ov011_02174630
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: existing follower ov011_func_02174660.c stays separate.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_020266AC 0x020266AC thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D1A4(u32 p);
void func_020266AC(u32 a, u32 b, u32 c);
void func_02174630(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((u32)func_020399A8()) && (p[0x8fb] & (1 << a))) {
        func_020266AC(((u32 *)p)[1], a, *c);
    }
}
