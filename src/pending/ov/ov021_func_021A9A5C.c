/*
 * function: func_021A9A5C
 * address:  0x021A9A5C
 * packet:   pkt_ov021_021A9A5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (switch register allocation; see docs/notes/pkt_ov021_021A9A5C.c.txt)
 *
 *
 * symbols:
 *   func_021A99E4  0x021A99E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Spec;
struct Unit {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

extern int func_021A99E4(u8 *a0, struct Unit *u, u16 id, struct Spec *spec);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

u8 func_021A9A5C(u8 *a0, struct Unit *u, u16 id, struct Spec *spec)
{
    int n = 0;
    u32 mode = 0;
    u8 *src;

    if (func_021A99E4(a0, u, id, spec) != 0)
        return u->f14;
    if (u->f08 >= 7)
        u->f08 = 0;
    switch (u->f08) {
    case 0:
        n = 12;
        src = a0 + 0x08;
        break;
    case 1:
        n = 12;
        src = a0 + 0x38;
        break;
    case 2:
        n = 12;
        src = a0 + 0x68;
        break;
    case 3:
        n = 5;
        src = a0 + 0x98;
        mode = 1;
        break;
    case 4:
        n = 5;
        src = a0 + 0xAC;
        mode = 1;
        break;
    case 5:
        n = 5;
        src = a0 + 0xC0;
        mode = 2;
        break;
    case 6:
        n = 5;
        src = a0 + 0xD4;
        mode = 2;
        break;
    }
    u->f10 = mode;
    u->f14 = n;
    MI_CpuCopy8(src, spec, n * 4);
    return n;
}
