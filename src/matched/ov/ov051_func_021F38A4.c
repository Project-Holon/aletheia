/*
 * function: func_021F38A4
 * address:  0x021F38A4
 * packet:   pkt_ov051_021F38A4
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F3D6C  0x021F3D6C  thumb  ov051
 *   func_021F3724  0x021F3724  thumb  ov051
 *   func_021F3718  0x021F3718  thumb  ov051
 *   func_021F3D04  0x021F3D04  thumb  ov051
 *   func_021F3958  0x021F3958  thumb  ov051
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DDC0  0x0216DDC0  thumb
 *   func_0216D588  0x0216D588  thumb
 */

extern void *func_021F3D6C(int a);
extern int func_021F3724(int a);
extern int func_021F3718(int a);
extern void func_021F3D04(int a, int b);
extern int func_021F3958(int a, int b, int c);
extern void *func_02188CB4(unsigned char *p);
struct VecFx32;
extern void func_021A3038(unsigned char *a, struct VecFx32 *b);
extern void func_02164208(int a, int *b, int c);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DDC0(void *a, int b, int c, int d);
extern int func_0216D588(int a);

int func_021F38A4(int a, int b)
{
    int v[3];
    int res;
    int x;
    int y;
    int h;
    unsigned int i;
    int *p;
    unsigned int n;
    int *r4;

    res = 0;
    r4 = func_021F3D6C(a);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)v);
    func_02164208(b, v, 1 << 16);
    x = (short)(((v[0] >> 4) / 4096));
    y = (short)(((v[2] >> 4) / 4096));
    n = func_021F3724(*r4);
    p = (int *)func_021F3718(*r4);
    i = 0;
    if (i < n)
        for (; i < n; i++) {
            if (p[0] == x && p[2] == y)
                func_021F3D04(a, i);
            p += 3;
        }
    h = func_0216DDC0(func_02188C7C((void *)a), x, y, 0);
    if (h != 0 && func_0216D588(h) == 0xfd)
        res = func_021F3958(a, h, b);
    return res;
}
