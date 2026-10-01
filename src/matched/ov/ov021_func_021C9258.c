/*
 * function: func_021C9258
 * address:  0x021C9258
 * packet:   pkt_ov021_021C9258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAB90  0x021DAB90  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
typedef struct { u32 a; V v; } T;
extern u32 func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern u8 d_021DAB90[];
void func_021C9258(u32 a, V *v)
{
    T t;
    t.a = func_021ABEA0(a, 0xb);
    t.v = *v;
    func_021ABFA8(a, d_021DAB90, 0, 0, &t, 0);
}
