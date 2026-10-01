/*
 * function: func_021A9080
 * address:  0x021A9080
 * packet:   pkt_ov021_021A9080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B404  0x0204B404  arm
 */

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    char pad0[0x124];
    int f124;
    int pad128[3];
    int f134;
} S;

extern void func_0204B404(int a, P *v, int b);

void func_021A9080(S *s, s16 x, s16 y)
{
    P v;
    v.x = x;
    v.y = y;
    func_0204B404(s->f124, &v, 0);
    s->f134 = 0;
}
