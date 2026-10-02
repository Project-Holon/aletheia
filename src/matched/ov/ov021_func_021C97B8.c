/*
 * function: func_021C97B8
 * address:  0x021C97B8
 * packet:   pkt_ov021_021C97B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C638  0x0218C638  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_02188CB4(unsigned char *p);
extern u32 func_02188C98(void *);
extern void func_021A3038(void *, int *);
extern u32 func_0218DC6C(u32);
extern u32 func_0218C638(u32, u32, int *);
extern void func_0218C69C(u32, u32, u32, u32);

int func_021C97B8(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        func_021A3038(func_02188CB4((unsigned char *)p[1]), v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C(func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C(h, r, 1, 2);
        }
        q[0]++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
