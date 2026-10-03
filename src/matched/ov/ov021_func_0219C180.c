/*
 * function: func_0219C180
 * address:  0x0219C180
 * packet:   pkt_ov021_0219C180
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D53B4  0x021D53B4  data  a4
 *   d_021D53D4  0x021D53D4  data  a4
 *
 * r = 0 is the first statement: its early live range pushes a to a stack
 * spill and leaves ip for &t.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern int func_02163E34(u32, Vec *, u32 *);
extern int func_021AB11C(u32 attr);
extern int d_021D53B4[][2];
extern int d_021D53D4[][2];

int func_0219C180(u32 a, Vec *p, int b, int c)
{
    int r;
    s16 x;
    s16 z;
    Vec t;
    u32 out;

    r = 0;
    t = *p;
    x = (p->x >> 4) / 4096;
    z = (p->z >> 4) / 4096;
    x += (s16)d_021D53B4[b][c];
    z += (s16)d_021D53D4[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (func_02163E34(a, &t, &out) == 1 && func_021AB11C(out) != 0) {
        r = 1;
    }
    return r;
}
