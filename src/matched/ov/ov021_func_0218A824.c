/*
 * function: func_0218A824
 * address:  0x0218A824
 * packet:   pkt_ov021_0218A824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Maps the held d-pad bits (up, down, left, right) to a direction and, unless
 * it is the current facing, none, or the movement mode is 1 or 2, tries
 * func_0218A784 with it. The two-value mode test is a switch.
 *
 * symbols:
 *   func_0218A784  0x0218A784  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
    u32 f1C;
    char pad20[0x04];
    u16 f24;
    u16 f26;
    char pad28[0x04];
    u32 f2C;
};

struct Ctx784;
extern int func_0218A784(struct Ctx784 *c, int a);

int func_0218A824(struct FieldCtx *p)
{
    u32 keys = p->f2C;
    u32 mode = p->f1C;
    int dir = 9;

    if (keys & 0x40)
        dir = 0;
    else if (keys & 0x80)
        dir = 1;
    else if (keys & 0x20)
        dir = 2;
    else if (keys & 0x10)
        dir = 3;
    if (dir == p->f24)
        return 0;
    if (dir == 9)
        return 0;
    switch (mode) {
    case 1:
    case 2:
        return 0;
    }
    return func_0218A784((struct Ctx784 *)p, dir);
}
