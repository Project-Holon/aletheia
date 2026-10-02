/*
 * function: func_0217FA38
 * address:  0x0217FA38
 * packet:   pkt_ov018_0217FA38
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_02176230  0x02176230  thumb  ov011
 *   func_0217CE08  0x0217CE08  thumb  ov018
 *   func_02012374  0x02012374  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0217F938  0x0217F938  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void *func_020124E4(void *);
u32 func_02012138(void *);
void *func_020120F4(void *);
void *func_0201210C(void *p);
u8 *func_02158344(int);
u8 func_02012B58(void *);
void func_02176230(u8 *a, u8 *b);
void *func_0217CE08(void *a, void *b, int c, int d);
void func_02012374(void *a, void *b);
u8 *func_020120F8(void *);
u16 func_02012AC8(void *);
int func_02013D5C(int);
void *func_0217F938(void *);

int func_0217FA38(void *a, int *state)
{
    void *s;
    u32 h;
    void *p2;
    void *p3;
    u8 *w;
    void *r;

    s = func_020124E4(a);
    h = func_02012138(s);
    p2 = func_020120F4(s);
    p3 = func_0201210C(s);
    w = func_02158344(h);
    switch (*state) {
    case 0:
        if (w == 0) {
            func_02012B58(p2);
        } else {
            func_02176230(w, w + 0x1AC);
        }
        r = func_0217CE08(s, p3, 0x117, 1);
        if (r == 0) {
            return 1;
        }
        func_02012374(a, r);
        (*state)++;
        break;
    case 1:
        if (func_02013D5C(func_02012AC8(func_020120F8(s))) == 1) {
            func_02012374(a, func_0217F938(s));
        }
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
