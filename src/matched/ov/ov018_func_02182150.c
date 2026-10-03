/*
 * function: func_02182150
 * address:  0x02182150
 * packet:   pkt_ov018_02182150
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021821B0  0x021821B0  thumb  ov018
 *   func_02012374  0x02012374  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;
struct Evt;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *);
extern void *func_021821B0(void *, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02188BE8(u32);
extern void func_0216D9E4(void *);

int func_02182150(void *a, int *state, int c)
{
    void *h;
    u8 *r;

    h = func_020124E4(a);
    r = func_0201210C(h);
    switch (*state) {
    case 0:
        func_0216D9A0((void *)func_02188C7C(r));
        func_02012374(a, func_021821B0(h, c));
        (*state)++;
        break;
    case 1:
        if (r != 0 && func_02188BE8((u32)r) == 1) {
            func_0216D9E4((void *)func_02188C7C(r));
            return 1;
        }
        break;
    }
    return 0;
}
