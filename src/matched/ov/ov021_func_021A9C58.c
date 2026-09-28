/*
 * function: func_021A9C58
 * address:  0x021A9C58
 * packet:   pkt_ov021_021A9C58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   data_021D8DD8  0x021D8DD8  data
 *   func_021A9B00  0x021A9B00  thumb
 *   func_021A9B68  0x021A9B68  thumb
 *   func_021A9BE8  0x021A9BE8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Slot14;
struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };
struct Unit {
    u8 pad00[0x10];
    u32 f10;
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 12;
    u32 b12 : 1;
    u32 b13 : 1;
};

extern u8 func_021A9B68(struct Unit *u, struct Spec *specs, u32 type);
extern void func_021A9B00(struct Spec *spec, struct Slot14 *s);
extern void func_021A9BE8(struct Unit *u, struct Spec *specs, struct Slot14 *s);
extern u32 (*const data_021D8DD8[])(u8 n);

void func_021A9C58(struct Unit *u, struct Spec *specs, struct Slot14 *s)
{
    u8 idx = 0xFF;

    if (u->b12)
        idx = func_021A9B68(u, specs, 8);
    else if (u->b13)
        idx = func_021A9B68(u, specs, 12);
    if (idx == 0xFF)
        idx = data_021D8DD8[u->f10](u->f14);
    func_021A9B00(&specs[idx], s);
    func_021A9BE8(u, specs, s);
}
