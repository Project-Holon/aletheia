/*
 * function: func_02163E7C
 * address:  0x02163E7C
 * packet:   pkt_ov010_02163E7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D80C  0x0216D80C  thumb
 *   func_0216D854  0x0216D854  thumb
 *   func_0216D818  0x0216D818  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_0216D824  0x0216D824  thumb
 *   func_021641E8  0x021641E8  thumb
 *   func_0216D848  0x0216D848  thumb
 *   func_021641F8  0x021641F8  thumb
 *   func_0216D87C  0x0216D87C  thumb
 *   func_02164280  0x02164280  thumb
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_02163E58  0x02163E58  thumb
 *   func_0216D85C  0x0216D85C  thumb
 */

typedef short s16;

typedef unsigned int   u32;
extern int func_0216D83C(void *p);
extern void func_0216D80C(int a, int b);
extern int func_0216D854(void *p);
extern void func_0216D818(int a, int b);
extern int func_0216D86C(void *p);
extern void func_0216D824(int a, int b);
extern int func_021641E8(int a);
extern void func_0216D848(int a, int b);
extern int func_021641F8(int a);
extern void func_0216D87C(int a, int b);
extern void func_02164280(int x, int y, int *p);
extern u32 func_0216D8AC(void *p);
extern void func_02163E58(int a, int *p, int *out);
extern void func_0216D85C(int a, int b);

void func_02163E7C(int a, int b)
{
    int v;
    int buf[3];

    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    func_0216D848(a, func_021641E8(b));
    func_0216D87C(a, func_021641F8(b));
    v = 0;
    func_02164280(func_0216D83C((void *)a), func_0216D86C((void *)a), buf);
    buf[1] = func_0216D8AC((void *)a);
    func_02163E58(a, buf, &v);
    func_0216D85C(a, (s16)((v >> 4) / 4096));
}
