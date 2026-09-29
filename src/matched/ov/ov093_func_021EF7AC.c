/*
 * function: func_021EF7AC
 * address:  0x021EF7AC
 * packet:   pkt_ov093_021EF7AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

extern void func_02045CAC(u32 a, u16 b, u32 c);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern D d_021F6398;

void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_02045CAC(d_021F6398.f1c, 0x11, d_021F6398.fc);
    func_0201EFA4(d_021F6398.f8, 0, b, 3, 0, 1);
    func_0201EFA4(d_021F6398.f8, 1, c, 3, 0, 1);
    func_0201EFA4(d_021F6398.f8, 2, d, 3, 0, 1);
    func_0201EFA4(d_021F6398.f8, 3, e, 3, 0, 1);
    func_0201EFA4(d_021F6398.f8, 4, f, 3, 0, 1);
    func_0201EFA4(d_021F6398.f8, 5, g, 3, 0, 1);
    func_0201F250(d_021F6398.f8, a, d_021F6398.fc);
}
