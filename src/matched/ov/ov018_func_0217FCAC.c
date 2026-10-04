/*
 * function: func_0217FCAC
 * address:  0x0217FCAC
 * packet:   pkt_ov018_0217FCAC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02158344  0x02158344  thumb ov010
 *   func_02167A54  0x02167A54  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb ov021
 *   func_0216D9A0  0x0216D9A0  thumb ov010
 *   func_0216D9E4  0x0216D9E4  thumb ov010
 *   func_0217FD34  0x0217FD34  thumb ov018
 */

typedef unsigned short u16;
struct Ctx;

typedef unsigned char  u8;
struct Evt;
struct Obj;
void *func_020124E4(struct Obj *p);
unsigned int func_02012138(const struct Ctx *p);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_02158344(int a0);
int func_02167A54(int *p, int i);
void *func_02188C7C(unsigned char *p);
void func_0216D9A0(void *x);
void func_0216D9E4(void *x);
void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f);

int func_0217FCAC(int x, int *st, int *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    int *m;

    m = (int *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        if (m == 0) {
            return 1;
        }
        if (func_02167A54((int *)m[2], obj[2]) == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((unsigned char *)obj[0]));
        func_02012374((struct Evt *)x, func_0217FD34(v, obj[0], (u8 *)m, obj[1], obj[2], *(u16 *)(obj + 3)));
        *st = *st + 1;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((unsigned char *)obj[0]));
        return 1;
    }
    return 0;
}
