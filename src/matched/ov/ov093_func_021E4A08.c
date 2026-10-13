/*
 * function: func_021E4A08
 * address:  0x021E4A08
 * packet:   pkt_ov093_021E4A08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q1;
struct S2;
struct Unk021D62A8;
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

u8 func_021E4A08(u8 *x, u8 idx, u8 lim, u8 *buf)
{
    u8 j;
    u8 i;
    u8 n = func_021B9B94((struct Q1 *)x);
    u8 *h;

    j = 0;
    for (i = 0; i < n; i++) {
        if (idx >= lim)
            break;
        h = func_021B9C00((struct S2 *)x, i);
        if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)h) != 0) {
            buf[idx] = BTL_POKEPARAM_GetPokeId(h);
            idx = idx + 1;
            j = j + 1;
        }
    }
    return j;
}
