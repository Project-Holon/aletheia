/*
 * function: func_02193B68
 * address:  0x02193B68
 * packet:   pkt_ov021_02193B68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193F34  0x02193F34  thumb  ov021
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;

extern void func_02193EB4(void *);
extern char *func_02193F34(void *, int);
extern int func_0200846C(int);
extern void func_020084A0(int);
extern void func_020084D4(int, char *);
extern void func_0200852C(int, int);
extern void func_0201F02C(int, int, int);
extern void func_020307B0(int);

void func_02193B68(void *a, int b, int c, int d, u16 e)
{
    char *q;
    int h;

    func_02193EB4(a);
    q = func_02193F34(a, c);
    h = func_0200846C((u16)((e & 0x7fff) | 0x8000));
    func_020084A0(h);
    func_020084D4(h, q + 0x38);
    func_0200852C(h, *(int *)(q + 0x48));
    func_0201F02C(b, d, h);
    func_020307B0(h);
}
