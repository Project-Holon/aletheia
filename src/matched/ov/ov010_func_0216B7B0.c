/*
 * function: func_0216B7B0
 * address:  0x0216B7B0
 * packet:   pkt_ov010_0216B7B0
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
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E3A0  0x0200E3A0  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200E3E8  0x0200E3E8  thumb
 *   func_02027100  0x02027100  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E394(void *a0);
extern void *func_0200E3A0(void *a);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void func_0200E3E8(u8 *bits, int id, u32 value);
extern void func_02027100(const void *src);

int func_0216B7B0(int c, int vm)
{
    void *r6;
    int a;
    int b;

    func_0215A5F4((void *)vm);
    r6 = func_0200E3A0(func_0200E394(func_02012EBC((struct Big *)func_0215A5E4((void *)vm))));
    a = func_02159B10((void *)c, (void *)vm);
    b = func_02159B10((void *)c, (void *)vm);
    func_0200E3E8(r6, (u8)a, b);
    func_02027100(r6);
    return 0;
}
