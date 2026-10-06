/*
 * function: func_021B7174
 * address:  0x021B7174
 * packet:   pkt_ov071_021B7174
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R;
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);

struct R *func_021B7174(u32 *p, int a, u16 heap)
{
    return func_02027F60((u8)a, 14, p[3], p[2], heap);
}
