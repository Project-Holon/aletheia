/*
 * function: func_021B6100
 * address:  0x021B6100
 * packet:   pkt_ov016_021B6100
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_021C0970  0x021C0970  arm
 *   d_021DAAA0  0x021DAAA0  data  a1
 */
extern int func_02087988(void);
extern void func_0208799C(int x);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
extern int func_02085D3C(void);
extern int func_021C0970(void *work, int language, int param);
extern char d_021DAAA0[];

void func_021B6100(int heap)
{
    int e;
    void *p;

    e = func_02087988();
    p = func_02030734(heap, 0x40000, 1, d_021DAAA0, 0x3d);
    if (func_02085D3C() == 0)
        func_021C0970(p, 1, 0);
    func_020307B0(p);
    func_0208799C(e);
    *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 1;
}
