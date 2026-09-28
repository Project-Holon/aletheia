/*
 * function: func_021C03F0
 * address:  0x021C03F0
 * packet:   pkt_021C03F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D4FE0  0x021D4FE0  arm
 *   func_021D52D4  0x021D52D4  arm
 *   func_021D51F0  0x021D51F0  arm
 *   func_021D5118  0x021D5118  arm
 *   g_021DE560     0x021DE560  data
 *   d_021DA3D8     0x021DA3D8  data
 *   d_021DA3DA     0x021DA3DA  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

struct G {
    u8  pad00[0x58];
    int f58;
    u8  pad5c[7];
    s8  f63;
};

extern int   func_021D4FE0(int a, int b);
extern void  func_021D52D4(int a, int b, int c);
extern void  func_021D51F0(int a, int b, int c);
extern void  func_021D5118(int a, int b, int c, int d);
extern struct G *g_021DE560;
extern u16   d_021DA3D8[][2];
extern u16   d_021DA3DA[][2];

void func_021C03F0(void)
{
    struct G *g;
    int sel = 0x44;
    int v;

    g = g_021DE560;
    if (g->f63 > 0xb)
        sel = 0x45;
    v = func_021D4FE0(g->f58, 0);
    func_021D52D4(0, sel, v);
    g = g_021DE560;
    func_021D51F0(g->f58, -1, 2);
    g = g_021DE560;
    func_021D5118(g->f58, -1, d_021DA3D8[g->f63][0], d_021DA3DA[g->f63][0]);
}
