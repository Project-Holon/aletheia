/*
 * function: func_021AEB3C
 * address:  0x021AEB3C
 * packet:   pkt_ov021_021AEB3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0216E818  0x0216E818  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021AEDAC  0x021AEDAC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern unsigned short func_02158F8C(unsigned char *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_02158F54(void *p);
extern int func_02158F58(int a0);
extern int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *vm, void *task);
extern void func_021AEDAC(u32 a);

int func_021AEB3C(u32 a, u32 b)
{
    u32 x, y, z, w;
    void *p;

    p = func_0215A5F4((void *)b);
    func_02158F8C((unsigned char *)p);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    w = func_02159B10((void *)a, (void *)b);
    func_0215897C(p, (void *)func_0216E818((int)func_02158F54(p), ((u32 *)func_02158F58((int)p))[1], 1, x, y, z, w));
    func_021AEDAC(b);
    return 1;
}
