/*
 * function: func_0219C20C
 * address:  0x0219C20C
 * packet:   pkt_ov021_0219C20C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D5414  0x021D5414  data  a4
 *   d_021D5434  0x021D5434  data  a4
 *
 * 2026-10-01: twin of func_0219C180 (same body, tables 021D5414/021D5434); same residue.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern int func_02163E34(u32, Vec *, u32 *);
extern u32 func_021AB11C(u32 a);
extern int d_021D5414[][2];
extern int d_021D5434[][2];

int func_0219C20C(u32 a, Vec *p, int b, int c)
{
    Vec t = *p;
    s16 x = (p->x >> 4) / 4096;
    s16 z = (p->z >> 4) / 4096;
    u32 out;
    int r = 0;

    x += (s16)d_021D5414[b][c];
    z += (s16)d_021D5434[b][c];
    t.x = x << 16;
    t.z = z << 16;
    if (func_02163E34(a, &t, &out) == 1 && func_021AB11C(out) != 0) {
        r = 1;
    }
    return r;
}
