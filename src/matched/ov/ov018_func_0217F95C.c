/*
 * function: func_0217F95C
 * address:  0x0217F95C
 * packet:   pkt_ov018_0217F95C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_0217F5A0  0x0217F5A0  thumb  ov018
 *   func_0217F4A0  0x0217F4A0  thumb  ov018
 *   func_0201210C  0x0201210C  thumb
 *   func_0217C458  0x0217C458  thumb  ov018
 *   func_0217FA1C  0x0217FA1C  thumb  ov018
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned char u8;

struct Desc;

void *func_020124E4(void *a0);
unsigned int func_02012138(void *a0);
u8 *func_02158344(int a0);
void func_0217F2B4(void *a0, void *a1);
int func_0217F5A0(void *p);
void func_0217F4A0(void *a0, int a1, int a2, int a3);
void *func_0201210C(void *p);
struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3);
void func_0217FA1C(void *p);
void func_0201235C(void *a0, void *a1);

int func_0217F95C(void *a0, int *state, void *a2)
{
    void *h;
    u8 *w;
    struct Desc *r;

    h = func_020124E4(a0);
    w = func_02158344(func_02012138(h));
    if (w == 0 && *state < 3) {
        *state = 3;
    }
    switch (*state) {
    case 0:
        w[0x93F] |= 8;
        func_0217F2B4(a2, h);
        if (func_0217F5A0(w + 0x1AC) == 3) {
            *state = 2;
        } else {
            func_0217F4A0(a2, 0x1A, 0, 0);
            (*state)++;
        }
        break;
    case 1:
        switch (func_0217F5A0(w + 0x1AC)) {
        case 2:
            break;
        case 3:
        default:
            (*state)++;
            break;
        }
        break;
    case 2:
        r = func_0217C458(h, func_0201210C(h), w, 0x15);
        func_0217FA1C(a2);
        func_0201235C(a0, r);
        return 0;
    case 3:
        func_0217FA1C(a2);
        return 1;
    }
    return 0;
}
