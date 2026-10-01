/*
 * function: func_021AE090
 * address:  0x021AE090
 * packet:   pkt_ov021_021AE090
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D92FC  0x021D92FC  data
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;
typedef struct M33 { int m[9]; } M33;
typedef struct Xf { V3 pos; V3 scale; M33 rot; } Xf;
typedef struct Q { u32 f0; u32 f4; u32 f8; u32 fc; } Q;

extern void func_0207ADC4(M33 *m);
extern void func_021AC1B8(u32 a, V3 *out);
extern void func_02047AC8(u32 a, Xf *x);
extern Xf d_021D92FC;

void func_021AE090(u32 a, Q **pq)
{
    Q *q = *pq;
    Xf x = d_021D92FC;

    func_0207ADC4(&x.rot);
    func_021AC1B8(a, &x.pos);
    func_02047AC8(q->fc, &x);
}
