/*
 * function: func_021F3794
 * address:  0x021F3794
 * packet:   pkt_ov059_021F3794
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3E84     0x021F3E84  data  a4
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021F3E84[];

extern void *func_02188D2C(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE760(void *a, void *b, int c);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern u8 *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);

void func_021F3794(void *a)
{
    int i;
    void *s;
    u8 *e;

    s = func_02188D2C(a);
    func_02189764(a, 1, func_02188C84(a), 0x28);
    func_021BE760(s, d_021F3E84, 0);
    func_021BE4B4(s, 0, 1, 1);
    func_021BE4B4(s, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        e = func_021BE674(s, 0, 0, (u16)i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 0, (u16)i, 0);
        e = func_021BE674(s, 0, 1, (u16)i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 1, (u16)i, 0);
    }
}
