/*
 * function: func_021A75BC
 * address:  0x021A75BC
 * packet:   pkt_ov021_021A75BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u16 h4;
} R;

typedef struct {
    int f0;
    u32 f4;
    R *f8;
} T;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
    T *f4;
} S;

int func_021A75BC(S *s, int a)
{
    T *t;
    if (s->b0) {
        t = s->f4;
        a = a % (t->f8->h4 << 12);
        t->f0 = a;
    }
    return a;
}
