/*
 * function: func_021A9A5C
 * address:  0x021A9A5C
 * packet:   pkt_ov021_021A9A5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A99E4  0x021A99E4  thumb
 * Addresses are Black-image addresses.
 *
 * Shape: n is a u8 (the return needs no truncation) and each case assigns
 * mode, then n, then src; that order keeps every case its own block with a
 * branch to the join and gives n r6, src r4.
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

extern int func_021A99E4(void *a0, struct Unit *u, u16 id, struct Spec *spec);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

u8 func_021A9A5C(u8 *a0, struct Unit *u, u16 id, struct Spec *spec)
{
    u8 n = 0;
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
        mode = 1;
        n = 5;
        src = a0 + 0x98;
        break;
    case 4:
        mode = 1;
        n = 5;
        src = a0 + 0xAC;
        break;
    case 5:
        mode = 2;
        n = 5;
        src = a0 + 0xC0;
        break;
    case 6:
        mode = 2;
        n = 5;
        src = a0 + 0xD4;
        break;
    }
    u->f10 = mode;
    u->f14 = n;
    MI_CpuCopy8(src, spec, n * 4);
    return n;
}
