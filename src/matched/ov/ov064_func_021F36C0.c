/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov064_021F36C0
 * region:   ov064
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
 *   func_020111E8  0x020111E8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3C20     0x021F3C20  data  a4
 *   d_021F3C30     0x021F3C30  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern char d_021F3C20[];
extern char d_021F3C30[];

extern int func_02188D2C(int a);
extern u16 func_02188C84(int a);
extern int *func_02189764(int a, int b, int c, int d);
typedef unsigned int   u32;
extern u32 func_020111E8(void);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE4B4(int a, int b, int c, int d);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);

void func_021F36C0(int a)
{
    int s;
    int *o;
    int i;
    u8 *e;

    s = func_02188D2C(a);
    o = func_02189764(a, 1, func_02188C84(a), 0x38);
    o[1] = 0;
    if (func_020111E8() == 0x14) {
        func_021BE760(s, d_021F3C20, 0);
    } else {
        func_021BE760(s, d_021F3C30, 0);
    }
    o[0] = 4;
    func_021BE4B4(s, 0, 0, 1);
    func_021BE4B4(s, 0, 1, 1);
    for (i = 0; i < 4; i++) {
        e = func_021BE674(s, 0, 0, i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 0, i, 0);
    }
    for (i = 0; i < 3; i++) {
        e = func_021BE674(s, 0, 1, i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 1);
        func_021BE700(s, 0, 1, i, 0);
    }
}
