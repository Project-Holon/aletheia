/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov065_021F36C0
 * region:   ov065
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     s is declared last (first or third put it in r4 and a0 in r5);
 *           the range test is `x - 3 <= 1` on the u32 result (a switch
 *           with cases 3 and 4 compiles two compares).
 *
 * symbols:
 *   d_021F3918     0x021F3918  data  a4
 *   d_021F38F8     0x021F38F8  data  a4
 *   d_021F3970     0x021F3970  data  a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_020113D8  0x020113D8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern char d_021F3918[];
extern char d_021F38F8[];
extern V d_021F3970;

extern u32   func_02188C80(void *p);
extern u32   func_020120F4(u32 a);
extern u32   func_02012EC4(u32 a);
extern int  *func_0200B3A4(u32 a, u32 b);
extern void *func_02188D2C(void *p);
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern int *func_021897BC(char *p, int idx);
extern u32   func_02012984(u32 a);
extern u32   func_020113D8(u32 a);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);

void func_021F36C0(void *a0)
{
    u32 sv;
    int *q;
    int *o;
    int i;
    void *b;
    void *s;

    sv = func_020120F4(func_02188C80(a0));
    q = func_0200B3A4(func_02012EC4(sv), 0x36);
    s = func_02188D2C(a0);
    func_02189764(a0, 1, func_02188C84(a0), 8);
    o = func_021897BC(a0, 1);
    o[0] = 0;
    if (func_020113D8(func_02012984(sv)) - 3 <= 1) {
        func_021BE760(s, d_021F3918, 0);
        o[1] = 1;
    } else {
        func_021BE760(s, d_021F38F8, 0);
        o[1] = 0;
    }
    *func_021BE480(s, 0, 0) = d_021F3970;
    func_021BE4A4(s, 0, 0, 1);
    func_021BE4B4(s, 0, 0, *q == 0);
    for (i = 0; i < 2; i++) {
        b = func_021BE674(s, 0, 0, i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
        func_021BE700(s, 0, 0, i, *q != 0);
    }
}
