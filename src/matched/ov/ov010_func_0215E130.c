/*
 * function: func_0215E130
 * address:  0x0215E130
 * packet:   pkt_ov010_0215E130
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02012F80  0x02012F80  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_02026454  0x02026454  thumb
 */

extern void func_0215A5F4(void *p);
extern void *func_0215A5DC(void *p);
extern void *func_0215A5E4(void *p);
extern void *func_02012138(void *p);
extern int *func_02012F80(void *p);
extern void func_02156BAC(int p);
extern int func_02156BCC(int p);
extern int func_02026454(void *p);

int func_0215E130(void *a, void *b)
{
    void *t;
    void *s;
    int *w;

    func_0215A5F4(b);
    t = func_0215A5DC(b);
    s = func_0215A5E4(b);
    t = func_02012138(t);
    w = func_02012F80(s);
    if (*w != 0) {
        func_02156BAC(*w);
        if (func_02156BCC(*w) == 1) {
            return 1;
        }
    }
    if (func_02026454(t) == 0) {
        return 1;
    }
    return 0;
}
