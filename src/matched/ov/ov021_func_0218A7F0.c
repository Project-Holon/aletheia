/*
 * function: func_0218A7F0
 * address:  0x0218A7F0
 * packet:   pkt_ov021_0218A7F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tries func_0218A784 for the current facing, then for the direction from
 * func_021A2FA4 when that differs and is not 9.
 *
 * symbols:
 *   func_0218A784  0x0218A784  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
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
extern int func_021A2FA4(void *p, u32 v);

int func_0218A7F0(struct FieldCtx *p)
{
    int r = func_0218A784((struct Ctx784 *)p, p->f24);
    int dir;

    if (r != 0)
        return r;
    dir = func_021A2FA4(p->f18, p->f2C);
    if (dir == 9 || dir == p->f24)
        return 0;
    r = func_0218A784((struct Ctx784 *)p, dir);
    if (r == 0)
        return 0;
    return r;
}
