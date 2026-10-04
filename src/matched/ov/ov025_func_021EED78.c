/*
 * function: func_021EED78
 * address:  0x021EED78
 * packet:   pkt_ov025_021EED78
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EED78 0x021EED78 thumb ov025
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */

typedef signed short s16;

typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A21E0(u32 *p);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_021EED78(int a)
{
    int *p;
    int q;
    s16 v[2];

    p = (int *)func_021A2630((unsigned char *)a);
    q = func_021A2638((unsigned char *)a);
    func_0204B454((struct Actor *)q, (struct PtS *)v, 0);
    switch (p[3]) {
    case 0:
        v[0] = v[0] + (s16)p[4];
        v[1] = v[1] + (s16)p[2];
        if (p[0]++ > p[1]) {
            p[3] = 1;
        }
        if (p[0] % 4 == 0) {
            p[4] = p[4] + p[5];
            if (p[2] > 1) {
                p[2] = p[2] - 1;
            }
        }
        func_0204B404((struct Obj *)q, (const struct Vec2 *)v, 0);
        break;
    case 1:
        func_021A21E0((u32 *)a);
        break;
    }
}
