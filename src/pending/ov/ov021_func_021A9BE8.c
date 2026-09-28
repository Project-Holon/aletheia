/*
 * function: func_021A9BE8
 * address:  0x021A9BE8
 * packet:   pkt_ov021_021A9BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (4 bytes: loop count u->f14 reloaded each iteration in the image; see docs/notes/pkt_ov021_021A9BE8.c.txt)
 *
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Slot14 { u16 f00; u8 pad02[2]; u8 f04; u8 f05; u8 pad06[0xE]; };
struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };
struct Unit {
    u8 pad00[0x14];
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 14;
    u32 b14 : 1;
};

void func_021A9BE8(struct Unit *u, struct Spec *specs, struct Slot14 *s)
{
    int varied;
    int i;
    u8 max = s->f04;
    u8 base = max;

    varied = 0;
    if (u->b14 == 0)
        return;
    for (i = 0; i < u->f14; i++) {
        if (varied == 0 && specs[i].lo != specs[i].hi)
            varied = 1;
        if (s->f00 == specs[i].id && max < specs[i].hi)
            max = specs[i].hi;
    }
    if (base + 5 <= max && varied == 1)
        s->f04 += 5;
    else
        s->f04 = max;
}
