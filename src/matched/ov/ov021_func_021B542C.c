/*
 * function: func_021B542C
 * address:  0x021B542C
 * packet:   pkt_ov021_021B542C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218F900  0x0218F900  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 w[3]; } V12;
typedef struct { u32 w[6]; } V24;

typedef struct {
    u16 h0;
    u16 h2;
    u32 f4;
    V12 v8;
    V24 v14;
} Src;

typedef struct {
    u32 pad0[3];
    V12 v0c;
    u32 pad18[3];
    u16 h24;
    u16 h26;
    u32 f28;
    u32 pad2c;
    V24 v30;
} Out;

extern int func_0215A5DC();
extern int func_0201210C();
extern int func_02188C58();
extern int func_02011330();
extern void func_02048F4C();
extern void func_0218F900();

int func_021B542C(int a0, int a1)
{
    Src s;
    Out o;
    int r5;
    int r6;
    int r4;

    r5 = func_02188C58(func_0201210C(func_0215A5DC(a1)));
    r6 = func_02011330(a0);
    r4 = func_02011330(a0);
    func_02048F4C(&s, 0xa3, r6);
    o.h24 = s.h0;
    o.h26 = s.h2;
    o.f28 = s.f4;
    o.v0c = s.v8;
    o.v30 = s.v14;
    func_0218F900(r5, &o, r4);
    return 0;
}
