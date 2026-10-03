/*
 * function: func_0216B6DC
 * address:  0x0216B6DC
 * packet:   pkt_ov010_0216B6DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern void *func_0200E394(void *a0);
struct Blk34;
extern void func_0200C334(struct Blk34 *p, u8 v);
extern void func_0200C344(struct Blk34 *p, u32 i, u8 v);

int func_0216B6DC(int a0, int a1)
{
    void *w;
    void *h;
    int i;

    func_0215A5F4((void *)a1);
    w = func_02012EBC((struct Big *)func_0215A5E4((void *)a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    func_0200C334(h, 0);
    for (i = 0; i < 3; i++)
        func_0200C344(h, (u8)i, 0xFF);
    return 0;
}
