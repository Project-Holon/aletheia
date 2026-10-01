/*
 * function: func_021C9064
 * address:  0x021C9064
 * packet:   pkt_ov021_021C9064
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DABB8  0x021DABB8  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 a; V v; u32 c; } T;
extern u32 func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern u8 d_021DABB8[];
void func_021C9064(u32 a, V *v, u32 c)
{
    T t;
    t.a = func_021ABEA0(a, 0xb);
    t.v = *v;
    t.c = c;
    func_021ABFA8(a, d_021DABB8, 0, 0, &t, 0);
}
