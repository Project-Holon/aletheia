/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov044_021F36C0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `adds r7,r5,#0` before the loop is a zero, not a counter copy: it runs
 * once (the loop branches back past it) and holds the constant 0 passed as
 * BE674's i/j and BE6B8's v, rematerialised off the counter's zero.
 *
 * symbols:
 *   d_021F39E8     0x021F39E8  data  ov044
 *   d_021F3A1C     0x021F3A1C  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021F392C  0x021F392C  thumb
 */

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int d_021F39E8;
extern V d_021F3A1C;

extern int func_02188D2C(int *p);
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, int j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void *func_021BE674(void *p, int i, int j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_021F392C(void *p);

void func_021F36C0(void *a0)
{
    void *r6;
    V *e;
    void *b;
    int i;

    r6 = (void *)func_02188D2C(a0);
    func_02189764(a0, 1, func_02188C84(a0), 0x14);
    func_021BE760(r6, &d_021F39E8, 0);
    e = func_021BE480(r6, 0, 0);
    *e = d_021F3A1C;
    func_021BE4A4(r6, 0, 0, 1);
    for (i = 0; i < 2; i++) {
        b = func_021BE674(r6, 0, 0, i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
    }
    func_021F392C(r6);
}
