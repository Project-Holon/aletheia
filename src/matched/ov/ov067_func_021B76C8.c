/*
 * function: func_021B76C8
 * address:  0x021B76C8
 * packet:   pkt_ov067_021B76C8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two constant byte tables copied to the stack, then read as [row][col].
 * A literal `u8 t[2][2] = {...}` gives an unresolved @N template; struct
 * assignment from an extern const keeps the pool word a data relocation.
 *
 * symbols:
 *   d_021B94B8  0x021B94B8  data  a1
 *   d_021B94BC  0x021B94BC  data  a1
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u8 v[2][2]; } T1;
typedef struct { u8 v[4][2]; } T2;

extern const T1 d_021B94B8;
extern const T2 d_021B94BC;

u8 func_021B76C8(u32 a, u32 b, u32 c)
{
    T1 t1 = d_021B94B8;
    T2 t2 = d_021B94BC;
    return t1.v[a][c] + t2.v[b][c];
}
