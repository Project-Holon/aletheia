/*
 * function: func_021A30C8
 * address:  0x021A30C8
 * packet:   pkt_ov021_021A30C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02188C5C  0x02188C5C  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021BB3C4  0x021BB3C4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;
typedef struct { s32 a, b; } Pair;

extern u32 func_02188CFC(u8 *p);
extern u16 func_02188C98(void *p);
struct VecFx32;
extern void func_021A3038(unsigned char *ctx, struct VecFx32 *out);
extern u32 func_021AB0D4(u16 z, VecFx32 *pos);
extern void *func_021A3074(void **ctx);
extern u32 func_02188C5C(u8 *p);
extern void func_0219E2F4(void *o, void *out);
extern u32 func_021BB3C4(void *w, Pair *v);

u32 func_021A30C8(void **ctx)
{
    u32 r;

    if (func_02188CFC(ctx[0]) == 0) {
        VecFx32 pos;
        u16 z = func_02188C98(ctx[0]);
        func_021A3038((unsigned char *)ctx, (struct VecFx32 *)&pos);
        r = func_021AB0D4(z, &pos);
    } else if (func_02188CFC(ctx[0]) == 1) {
        Pair v;
        void *o = func_021A3074(ctx);
        void *w = (void *)func_02188C5C(ctx[0]);
        func_0219E2F4(o, &v);
        r = func_021BB3C4(w, &v);
    }
    return r;
}
