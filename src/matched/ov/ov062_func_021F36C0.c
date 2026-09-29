/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov062_021F36C0
 * region:   ov062
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   d_021F3768     0x021F3768  data  a4
 *   d_021F3790     0x021F3790  data  a4
 */

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern V3 d_021F3768;
extern V3 d_021F3790;

extern int func_02188C80(int a);
extern int func_020120F4(int a);
extern int func_02012EC4(int a);
extern int *func_0200B3A4(int a, int b);
extern int func_02188D2C(int a);
extern void func_021BE760(int a, void *b, int c);
extern int func_021BE480(int a, unsigned b, int c);
extern void func_021BE4A4(int a, int b, int c, int d);
extern void func_021BE700(int a, int b, int c, int d, int e);
extern void func_021BE4B4(int a, int b, int c, int d);

void func_021F36C0(int a)
{
    int *q;
    int s;

    q = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(a))), 0x34);
    s = func_02188D2C(a);
    func_021BE760(s, &d_021F3768, 0);
    *(V3 *)func_021BE480(s, 0, 0) = d_021F3790;
    func_021BE4A4(s, 0, 0, 1);
    func_021BE700(s, 0, 0, 0, 1);
    if (*q != 0)
        func_021BE4B4(s, 0, 0, 1);
}
