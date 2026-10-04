/*
 * function: func_0217FB94
 * address:  0x0217FB94
 * packet:   pkt_ov018_0217FB94
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217FC08  0x0217FC08  thumb  ov018
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 fC;
} Req;

struct Evt;
struct Obj;
void *func_020124E4(struct Obj *p);
struct Ctx;
unsigned int func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void *func_02188C7C(unsigned char *p);
void func_0216D9A0(void *x);
void func_0216D9E4(void *x);
void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f);
void func_02012374(struct Evt *evt, struct Evt **out);

int func_0217FB94(int a, int *state, Req *req)
{
    int s;
    u8 *w;

    s = (int)func_020124E4((struct Obj *)a);
    w = (u8 *)func_02158344(func_02012138((const struct Ctx *)s));
    switch (*state) {
    case 0:
        if (w == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((u8 *)req->f0));
        func_02012374((struct Evt *)a, func_0217FC08(s, req->f0, w, req->f4, req->f8, req->fC));
        (*state)++;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((u8 *)req->f0));
        return 1;
    }
    return 0;
}
