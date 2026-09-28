/*
 * function: func_02202608
 * address:  0x02202608
 * packet:   pkt_02202608
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203F5C  0x02203F5C  data  ov135

 * Create the table entry and register the 0x47 callback against it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_020173EC(u8 *p, u32 k);
extern void func_02030734(u8 *p, u32 h, u32 b, u32 t, u32 c);
extern u8 g_02203F5C[];

void func_02202608(u8 *p, u32 k)
{
    u32 h = func_020173EC(p, k);

    func_02030734(p, h, 0, (u32)g_02203F5C, 0x47);
}
