/*
 * function: func_0203ED84
 * address:  0x0203ED84
 * packet:   pkt_0203EC7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F4      0x021469F4  data
 */

typedef unsigned char u8;
struct S {
    unsigned int a : 2;
    unsigned int b : 30;
};
extern int *g_021469F4;
extern int func_0203996C(int v);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_0203D4D0(int a0, int a1, int a2, int a3, void *a4, int a5, int a6, int a7);
void func_0203ED84(int a0)
{
    struct S sv;
    int t;
    if (*(int *)((char *)g_021469F4 + 0x2c) == 1)
        t = func_0203996C(0xff);
    else
        t = (int)func_020399A8();
    sv.a = a0;
    sv.b = *(int *)((char *)g_021469F4 + 0x24);
    func_0203D4D0(t, *(u8 *)((char *)g_021469F4 + 0x28), 0xf, 4, &sv, 0, 1, 0);
}
