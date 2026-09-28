/*
 * function: func_021AA35C
 * address:  0x021AA35C
 * packet:   pkt_ov021_021AA35C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB100  0x021AB100  thumb
 *   func_021AB140  0x021AB140  thumb
 *   func_021AB29C  0x021AB29C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02188CB4(void *p);
extern u16 func_02188C98(void *p);
extern u32 func_021A30C8(void *q);
extern int func_021AB100(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB140(u16 x);
extern int func_021AB29C(u16 x);

int func_021AA35C(void **ctx, int mode, u8 *out)
{
    void *y = func_02188CB4(ctx[0]);
    u32 attr;
    u16 fl;
    u16 t;

    func_02188C98(ctx[0]);
    *out = 0;
    attr = func_021A30C8(y);
    if (func_021AB100(attr) == 0)
        return 0xFF;
    fl = func_021AB0F8(attr);
    if (mode != 1 && (fl & 4) == 0)
        return 0xFF;
    t = func_021AB0F0(attr);
    if (func_021AB140(t))
        *out += 10;
    if (fl & 2) {
        if (mode == 1)
            return 4;
        return 3;
    }
    if (mode == 1)
        return 2;
    if (func_021AB29C(t))
        return 1;
    return 0;
}
