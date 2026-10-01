/*
 * function: func_0218FD88
 * address:  0x0218FD88
 * packet:   pkt_ov021_0218FD88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0218FDD4  0x0218FDD4  thumb
 *
 * 2026-10-01: 2-instruction scheduler tie. Image stores out->y (str r0,[r4,#4])
 * before bumping p/q by 8 for the third call; every spelling tried (int arrays,
 * pointer post-increment, const params, explicit temporaries, scoped address
 * locals) hoists the adds above the store. Rest of the body is byte-identical.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { int x, y, z; } Vec3;

extern int func_0218FDD4(int *p, int *q, int n, int d);

void func_0218FD88(Vec3 *p, Vec3 *q, int n, int d, Vec3 *out)
{
    if (n == 0)
        *out = *q;
    out->x = func_0218FDD4(&p->x, &q->x, n, d);
    out->y = func_0218FDD4(&p->y, &q->y, n, d);
    out->z = func_0218FDD4(&p->z, &q->z, n, d);
}
