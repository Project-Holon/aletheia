/*
 * function: func_021BA310
 * address:  0x021BA310
 * packet:   pkt_ov021_021BA310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021BA2B4  0x021BA2B4  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 */

extern void *func_021B8220(void *p);
extern void *func_021B821C(void *p);
extern void func_021BA2B4(void *p);
extern void func_0218EC54(void *p);
extern void func_021B8314(void *p, void *buf);
extern void func_0218EC90(void *p, void *buf);

void func_021BA310(void *p)
{
    void *a;
    void *b;
    int buf[3];

    a = func_021B8220(p);
    b = func_021B821C(p);
    func_021BA2B4(p);
    func_0218EC54(b);
    func_021B8314(a, buf);
    func_0218EC90(b, buf);
}
