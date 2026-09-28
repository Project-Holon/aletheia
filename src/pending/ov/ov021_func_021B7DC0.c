/*
 * function: func_021B7DC0
 * address:  0x021B7DC0
 * packet:   pkt_ov021_021B7DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   PENDING
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

typedef struct { s32 x, y, z; } VecFx32;
typedef struct { u16 w, h; } Size16;
typedef struct { u16 a, b; Size16 sz; } Rect4;

struct Cam {
    u8 pad00[0x50];
    VecFx32 f50;
    Rect4 f5C;
    u8 pad64[8];
    Rect4 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

void func_021B7DC0(struct Cam *c, Rect4 *out)
{
    out->a = c->f5C.a;
    out->b = c->f5C.b;
    out->sz = c->f5C.sz;
}
