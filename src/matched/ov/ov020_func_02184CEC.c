/*
 * function: func_02184CEC
 * address:  0x02184CEC
 * packet:   pkt_ov020_02184CEC
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAAF0  0x021AAAF0  thumb  ov021
 */

typedef unsigned short u16;

void *func_020120F4(void *p);
void *func_0201210C(void *p);
u16 func_02012984(void *p);
u16 func_02188C9C(int x);
int func_02188CE8(int x);
void func_021AAAF0(int x, int y);

void func_02184CEC(int *o, void *p)
{
    void *a = func_020120F4(p);
    void *b = func_0201210C(p);
    u16 c = func_02012984(a);

    o[0] = (int)p;
    o[1] = (int)a;
    o[2] = b;
    *(u16 *)(o + 3) = func_02188C9C(b);
    o[0x10] = 0;
    o[0x11] = 0;
    *(u16 *)((char *)o + 0x48) = c;
    *(u16 *)((char *)o + 0x4a) = c;
    func_021AAAF0(func_02188CE8(o[2]), 1);
}
