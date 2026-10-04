/*
 * function: func_0219BDC4
 * address:  0x0219BDC4
 * packet:   pkt_ov021_0219BDC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   d_021D5474     0x021D5474  data   ov021  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0216D684(u32, u32);
typedef unsigned short u16;
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u32);
extern void func_0216D568(void *p, u32 v);
extern void func_0216D8C0(u32, void *);

typedef struct { u32 a, b, c; } T12;
extern T12 d_021D5474;

void func_0219BDC4(u32 a, u32 b)
{
    T12 t;
    u32 k = 8;
    *(u8 *)(func_0216D684(a, 8) + 1) = b;
    func_0216D674((void *)a, 0);
    func_0216DA50(a);
    func_0216D568((void *)a, k << 12);
    t = d_021D5474;
    func_0216D8C0(a, &t);
}
