/*
 * function: func_02166734
 * address:  0x02166734
 * packet:   pkt_ov010_02166734
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The five unlabelled leaf callees are filed as their own shards
 * (matched witnesses): ov010_func_02166658.c, ov021_func_021C87A0.c,
 * ov021_func_021C87AC.c, ov021_func_021C87B8.c, ov021_func_021C87C8.c.
 * (ov128_func_021C87A0.c is a different overlay's function at that
 * address; ov010 runs with ov021 loaded.)
 * lever (wave 82 R8): each arm writes the store `*(u16 *)a = ...` out
 *   itself, case 8 included (`if (...) *a = 1; else *a = 0;`). Cross-jumping
 *   then leaves cases 5-8 branching onto case 4's `b` and case 8's else as a
 *   dead `b` onto default. A shared `v` stored after the switch is 170 B
 *   (36 bytes out); with case 8's `else v = 0;` it is 172 B but DIFF21
 *   (a/p colours swapped, direct branches). An inline switch helper is the
 *   same DIFF21.
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_0215A5DC  0x0215A5DC  thumb ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_02166658  0x02166658  thumb ov010
 *   func_021C87A0  0x021C87A0  thumb ov021
 *   func_021C87AC  0x021C87AC  thumb ov021
 *   func_021C87B8  0x021C87B8  thumb ov021
 *   func_021C87C8  0x021C87C8  thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
struct Big;
struct Stream;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012ED0(struct Big *p);
extern u32 func_02159B10(void *, void *);
extern u16 func_02011330(struct Stream *s);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02166658(void *p, u32 i);
extern u32 func_021C87A0(void *p, u32 i);
extern u32 func_021C87AC(void *p, u32 i);
extern u32 func_021C87B8(void *p, u32 i, u32 j);
extern u32 func_021C87C8(void *p, u32 i);

int func_02166734(void *a, void *b)
{
    u8 *p;
    u32 x;
    u16 k;
    u32 y;

    func_0215A5F4(b);
    p = func_02012ED0((struct Big *)func_020120F4((const struct Ctx *)func_0215A5DC(b)));
    x = func_02159B10(a, b);
    k = func_02011330((struct Stream *)a);
    y = func_02159B10(a, b);
    a = func_02159AE8(a, b);
    switch (k) {
    case 4:
        *(u16 *)a = func_02166658(*(void **)p, x);
        break;
    case 5:
        *(u16 *)a = func_021C87A0(*(void **)p, x);
        break;
    case 6:
        *(u16 *)a = func_021C87AC(*(void **)p, x);
        break;
    case 7:
        *(u16 *)a = func_021C87B8(*(void **)p, x, y);
        break;
    case 8:
        if (func_021C87C8(*(void **)p, x) != 0)
            *(u16 *)a = 1;
        else
            *(u16 *)a = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    default:
        *(u16 *)a = 0;
        break;
    }
    return 0;
}
