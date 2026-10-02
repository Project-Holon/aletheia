/*
 * function: func_0218A240
 * address:  0x0218A240
 * packet:   pkt_ov021_0218A240
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218A278  0x0218A278  thumb  ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02189A70  0x02189A70  thumb  ov021
 *   func_021F3B10  0x021F3B10  thumb  ov053
 *   func_0218A6E8  0x0218A6E8  thumb  ov021
 */

int func_0218A278(void *sys, unsigned char *pos);
void *func_0201210C(void *p);
int func_02188D20(void *h);
void func_021BC5BC(int x);
int func_02189A70(void *h);
void func_021F3B10(void);
void func_0218A6E8(void *p, void *h);

int func_0218A240(void *p, unsigned char *pos)
{
    void *h;
    int r = func_0218A278(p, pos);
    if (r != 0) {
        h = func_0201210C(p);
        func_021BC5BC(func_02188D20(h));
        if (func_02189A70(h) != 0)
            func_021F3B10();
        func_0218A6E8(p, h);
    }
    return r;
}
