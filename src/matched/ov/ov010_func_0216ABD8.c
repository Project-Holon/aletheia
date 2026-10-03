/*
 * function: func_0216ABD8
 * address:  0x0216ABD8
 * packet:   pkt_ov010_0216ABD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0216AF1C  0x0216AF1C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0216AF74  0x0216AF74  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159B10();
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0216AED0(void *p, u32 id);
extern int func_0216AF1C();
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Desc;
extern struct Desc *func_0216AF74(void *a0, void *a1, int a2, int a3, unsigned short *a4, unsigned short a5);
extern void func_0215897C(void *vm, void *task);

int func_0216ABD8(int a0, int a1)
{
    int buf;
    int *pb;
    int k;
    u16 *p;
    int q;
    void *s;
    void *t;
    void *r;

    pb = &buf;
    k = func_02159B10(a0, a1);
    p = func_02159AE8((void *)a0, (void *)a1);
    r = func_0216AED0((void *)a1, k);
    if (r != 0) {
        q = func_0216AF1C(a1, r, 4, pb);
        if (q != 0) {
            s = func_0215A5F4((void *)a1);
            t = func_0215A5DC((void *)a1);
            func_0215897C(s, func_0216AF74(t, func_0201210C((void *)t), q, *pb, p, 4));
        }
    }
    return 1;
}
