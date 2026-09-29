/*
 * function: func_021F37C0
 * address:  0x021F37C0
 * packet:   pkt_ov052_021F37C0
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3998  0x021F3998  thumb  ov052
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021D0218  0x021D0218  thumb  ov021
 */

extern int func_02188C84(void *);
extern int func_02188C80(void *);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern int func_02188C9C(void *);
extern void func_021F3998(int, int *, int *);
extern char *func_0200B3A4(unsigned, int);
extern int func_02188CD0(void *);
extern int func_021D0218(int, int, int);

void func_021F37C0(void *a, int b, int c)
{
    int s1;
    int s0;
    unsigned h;
    int *r5;

    func_02188C84(a);
    h = func_02012EC4(func_020120F4(func_02188C80(a)));
    func_021F3998(func_02188C9C(a), &s0, &s1);
    r5 = *(int **)(func_0200B3A4(h, s0) + 0x24);
    *r5 = func_021D0218(func_02188CD0(a), b, c);
}
