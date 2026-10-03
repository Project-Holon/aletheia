/*
 * function: func_0219BE70
 * address:  0x0219BE70
 * packet:   pkt_ov021_0219BE70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   d_021D5480     0x021D5480  data   ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 a, b, c; } T12;
extern T12 d_021D5480;
extern u8 *func_0216D69C(u32);
extern void func_0219BF3C(int a, u32 v);
extern void func_0216D8C0(u32, void *);
extern void func_0216D568(u32, u32);

void func_0219BE70(u32 a)
{
    u8 *p = func_0216D69C(a);
    T12 t;
    p[0] = 0;
    func_0219BF3C(a, 0);
    if (p[2] == 0) {
        t = d_021D5480;
        func_0216D8C0(a, &t);
        func_0216D568(a, 2 << 14);
    }
}
