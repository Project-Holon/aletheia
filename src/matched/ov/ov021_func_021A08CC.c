/*
 * function: func_021A08CC
 * address:  0x021A08CC
 * packet:   pkt_ov021_021A08CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0207CB68  0x0207CB68  arm
 *   func_0207CAA4  0x0207CAA4  arm
 *   func_0207D184  0x0207D184  arm
 * Addresses are Black-image addresses.
 * The `const` on `in` is what puts its three loads ahead of the stores in
 * the original's order (in[2], in[1], in[0]; stores o[1], o[2], o[0]).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } V32;

extern void func_0207CB68(const s16 *a, u32 b, s16 *c);
extern s32 func_0207CAA4(const s16 *a, u32 b);
extern u16 func_0207D184(s32 x);

static inline void set(V32 *o, s32 x, s32 y, s32 z)
{
    o->x = x;
    o->y = y;
    o->z = z;
}

void func_021A08CC(s32 *o, const s16 *in, u32 c)
{
    s16 v[3];

    set((V32 *)o, in[0], in[1], in[2]);
    func_0207CB68(in, c, v);
    set((V32 *)(o + 3), v[0], v[1], v[2]);
    *(u16 *)(o + 6) = func_0207D184(func_0207CAA4(in, c));
}
