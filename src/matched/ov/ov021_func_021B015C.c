/*
 * function: func_021B015C
 * address:  0x021B015C
 * packet:   pkt_ov021_021B015C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A864  0x0215A864  thumb  ov010
 *   func_0215A990  0x0215A990  thumb  ov010
 *   func_0215A954  0x0215A954  thumb  ov010
 */

typedef struct {
    int h;
    int flag;
} Ctx;

typedef unsigned char  u8;
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(char *a0);
extern void func_0215A864(int *p);
extern int func_0215A990(u8 *a);
extern int func_0215A954(u8 *a);

int func_021B015C(int a0, int *st, Ctx *c)
{
    int r;

    switch (*st) {
    case 0:
        func_0215A684((int *)c->h, 8);
        (*st)++;
    case 1:
        if (func_0215A690((char *)c->h) == 1) {
            func_0215A864((int *)c->h);
            (*st)++;
        }
        break;
    case 2:
        if (c->flag != 0)
            r = func_0215A990((u8 *)c->h);
        else
            r = func_0215A954((u8 *)c->h);
        if (r == 1)
            return 1;
        break;
    }
    return 0;
}
