/*
 * function: func_021877A8
 * address:  0x021877A8
 * packet:   pkt_ov020_021877A8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * c must be u8 (as in the twin func_02187808): with an int c the scheduler
 * hoists its spilled reload above the strb of d.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124EC  0x020124EC  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0202E8B8  0x0202E8B8  thumb
 *   func_02187C20  0x02187C20  thumb  ov020
 *   func_021876E0  0x021876E0  thumb  ov020
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { int a; int b; u16 c; int d; int e; u8 f; u8 g; u8 pad[10];
                 int h; int i; } T;

extern int func_021876E0(void *, int *, char *);
extern void *func_020122C0(void *, int, int (*)(void *, int *, char *), int);
extern void *func_020124E8(void *);
extern int func_020124EC(void *);
extern u16 func_02188C84(int);
extern u8 func_0202E8B8(int);
extern void func_02187C20(T *, int, int);

void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f)
{
    void *r7 = func_020122C0((void *)a, 0, func_021876E0, 0x28);
    T *t = func_020124E8(r7);
    int x = func_020124EC(r7);
    t->a = a; t->b = b; t->c = func_02188C84(b); t->d = 0; t->e = 0;
    t->f = d; t->g = func_0202E8B8(c); t->h = e; t->i = f;
    func_02187C20(t, x, 0);
    return r7;
}
