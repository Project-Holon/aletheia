/*
 * function: func_021A99E4
 * address:  0x021A99E4
 * packet:   pkt_ov021_021A99E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02005728  0x02005728  thumb
 *   func_021A99A8  0x021A99A8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Entry8 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 pad07; };
struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };
struct Unit {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

extern const struct Entry8 *func_021A99A8(void *p);
extern u32 func_02005728(u32 v);

int func_021A99E4(void *a0, struct Unit *u, u16 id, struct Spec *spec)
{
    const struct Entry8 *e = func_021A99A8(u->f00);

    if (e == 0 || e->f00 != id)
        return 0;
    if (u->f08 != 0)
        return 0;
    if (func_02005728(1000) > 400)
        return 0;
    spec->id = e->f02;
    spec->lo = e->f05;
    spec->hi = e->f06;
    spec->lvl = e->f04;
    u->f10 = 3;
    u->f14 = 1;
    return 1;
}
