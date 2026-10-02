/*
 * function: func_021BD19C
 * address:  0x021BD19C
 * packet:   pkt_ov210_021BD19C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BCE58  0x021BCE58  thumb  ov210
 *   func_02021ED8  0x02021ED8  thumb
 *   func_021BFF68  0x021BFF68  thumb  ov210
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE314  0x021BE314  thumb  ov210
 *   func_021BE2F4  0x021BE2F4  thumb  ov210
 *   func_021BE324  0x021BE324  thumb  ov210
 *   func_021BEDB8  0x021BEDB8  thumb  ov210
 *   func_021BCF38  0x021BCF38  thumb  ov210
 *   func_0202EA40  0x0202EA40  thumb
 * 2026-10-02: bytes identical. Only blocker: func_021BE314 has no witness yet.
 * Lane 07 filed src/matched/ov/ov210_func_021BE314.c (EXACT); after its shard
 * exists, re-verify; this should then be EXACT and move to src/matched/ov/.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern int func_021BCE58(u8 *p);
extern u32 func_02021ED8(u32 a);
extern u32 func_021BFF68(u8 *p);
extern void func_020061E4(u32 id);
extern u32 func_021BE314(u8 *p, u32 a);
extern u32 func_021BE2F4(u8 *p, u32 a, u32 b, u32 c);
extern void func_021BE324(u8 *p);
extern void func_021BEDB8(u8 *p, u32 a, u32 b);
extern void func_021BCF38(u8 *p);
extern void func_0202EA40(u32 a);

u32 func_021BD19C(u8 *p)
{
    if (func_021BCE58(p) == 1 || func_02021ED8(*(u32 *)(p + 0xc)) != 0) {
        return 4;
    }
    switch (func_021BFF68(p)) {
    case 0:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 0, func_021BE314(p, 9));
    case 1:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 1, func_021BE314(p, 12));
    case 2:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 2, func_021BE314(p, 15));
    case 3:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 3, func_021BE314(p, 18));
    case 4:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 4, func_021BE314(p, 21));
    case 5:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 5, 7);
    case 6:
        func_020061E4(0x54c);
        return func_021BE2F4(p, 0, 6, 6);
    case 7:
        func_020061E4(0x646);
        func_021BE324(p);
        break;
    case 8:
        func_020061E4(0x556);
        *(u32 *)(*(u8 **)p + 0xc) = 2;
        func_021BEDB8(p, 3, 8);
        return func_021BE2F4(p, 1, 3, 0x1a);
    case 9:
        func_020061E4(0x551);
        func_021BCF38(p);
        *(u32 *)(*(u8 **)p + 0xc) = 1;
        func_021BEDB8(p, 2, 9);
        return func_021BE2F4(p, 1, 2, 0x1a);
    case (u32)-4:
        func_020061E4(0x548);
        break;
    case (u32)-3:
        func_020061E4(0x548);
        break;
    case (u32)-2:
        func_020061E4(0x551);
        func_021BCF38(p);
        *(u32 *)(*(u8 **)p + 0xc) = 1;
        func_021BEDB8(p, 2, 9);
        return func_021BE2F4(p, 1, 2, 0x1a);
    }
    func_0202EA40(*(u32 *)(p + 0x2b4));
    return 4;
}
