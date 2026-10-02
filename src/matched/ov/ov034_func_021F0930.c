/*
 * function: func_021F0930
 * address:  0x021F0930
 * packet:   pkt_ov034_021F0930
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0930 0x021F0930 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_02043598 0x02043598 arm
 */

extern int func_020120F4(int);
extern void *func_02012934(void *p);
extern unsigned int func_0201AA18(int);
extern void func_0204B3B4(int);
extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
extern void func_0204AFD8(int);
extern void func_0204B1CC(int);
extern void func_02043598(int, int);

void func_021F0930(int *p)
{
    unsigned int i;
    void *n;

    n = func_02012934(func_020120F4(p[0]));
    for (i = 0; i < func_0201AA18(n); i++) {
        func_0204B3B4(p[0x15 + i]);
        func_0204A8D4(p[0x25 + i]);
    }
    for (i = 6; i <= 15; i++)
        func_0204B3B4(p[0x15 + i]);
    func_0204A8D4(p[0x2B]);
    func_0204ADA4(p[0x34]);
    func_0204ADA4(p[0x35]);
    func_0204AFD8(p[0x41]);
    func_0204AFD8(p[0x42]);
    func_0204B1CC(p[0x14]);
    func_02043598(0x10, 0);
}
