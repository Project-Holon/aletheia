/*
 * function: func_021B66B8
 * address:  0x021B66B8
 * packet:   pkt_ov021_021B66B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_021B6934  0x021B6934  thumb
 *   func_021B6708  0x021B6708  thumb
 *   func_021B6904  0x021B6904  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *, void *);
extern void *func_0215A5E4(void *);
extern int func_021B6934(void *);
extern void func_021B6708(void *, int);
extern void func_021B6904(void *);

u32 func_021B66B8(void *a, void *b)
{
    u32 op = func_02159B10(a, b);
    u16 *out = func_02159AE8(a, b);
    void *x = func_0215A5E4(b);

    switch (op) {
    case 0:
        if (func_021B6934(x) < 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 1:
        func_021B6904(b);
        break;
    case 2:
        func_021B6708(b, *out);
        func_021B6904(b);
        break;
    }
    return 0;
}
