/*
 * function: func_021A834C
 * address:  0x021A834C
 * packet:   pkt_ov021_021A834C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A8268  0x021A8268  thumb
 */

typedef struct {
    int pad[14];
    int f38;
} R;

typedef struct {
    R *f0;
} S;

typedef unsigned int   u32;
extern int func_021A8268(u32 a);

int func_021A834C(S *s)
{
    R *p = s->f0;
    if (func_021A8268((u32)s)) {
        return 0;
    }
    if (p->f38 != 2) {
        return 1;
    }
    return 0;
}
