/*
 * function: func_021A957C
 * address:  0x021A957C
 * packet:   pkt_ov021_021A957C
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
 *   func_0200D488  0x0200D488  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_021A996C  0x021A996C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Unit {
    void *f00;
    void *f04;
};

extern int func_0200D488(void *party, int i);
extern void *func_0200D4AC(void *party, int i);
extern u32 func_0200D4B8(void *mon, int field);
extern int func_021A996C(struct Unit *u, u8 n);
extern u32 func_02005728(u32 v);

void *func_021A957C(void *a0, struct Unit *u, u32 want)
{
    void *buf[2];
    u8 n = 0;
    u8 i;
    void *m;

    for (i = 0; i < 2; i++) {
        if (func_0200D488(u->f04, i) == 0)
            continue;
        m = func_0200D4AC(u->f04, i);
        if (func_0200D4B8(m, 1) != want)
            continue;
        if (func_021A996C(u, func_0200D4B8(m, 6)) != 0)
            continue;
        buf[n++] = m;
    }
    if (n == 0 || func_02005728(1000) < 500)
        return 0;
    return buf[func_02005728(n)];
}
