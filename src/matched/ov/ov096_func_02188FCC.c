/*
 * function: func_02188FCC
 * address:  0x02188FCC
 * packet:   pkt_ov096_02188FCC
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov070
 */

extern int func_0201134C(int);
extern int func_0218A160(int, int);
extern int func_021B8DE4(int, int);
extern int func_021B9AF8(int, int);
extern int func_021B99B8(int, int);
extern int func_021B9B94(int);
extern int func_0218A308(int, int);
extern int func_021D5B68(void);
extern int func_021D62A8(int);
extern int func_0218A0F4(int, int, int, int, int);

void func_02188FCC(int a, int b, int c)
{
    int t0;
    int t1;
    int n;
    int handle;
    int i;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    n = func_021B8DE4(*(int *)(b + 0xb0), func_0218A160(b, t0));
    handle = func_021B9AF8(*(int *)(b + 0xb8), n);
    for (i = func_021B99B8(*(int *)(b + 0xb0), n);
         i < func_021B9B94(handle); i++) {
        int t = func_0218A308(handle, (unsigned char)i);

        if (func_021D5B68() == 0) {
            if (func_0218A0F4(a, c, func_021D62A8(t), 0, t1) != 0)
                break;
        }
    }
}
