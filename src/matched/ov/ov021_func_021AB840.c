/*
 * function: func_021AB840
 * address:  0x021AB840
 * packet:   pkt_ov021_021AB840
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A39C  0x0204A39C  arm
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned int u32;

typedef struct {
    int f0;
    u32 f4;
    int f8[2];
} S;

extern int func_0204A39C(int a, int b, int c, int d, u32 *out);

void func_021AB840(S *s, int i, int b, int d)
{
    u32 out;
    s->f0 = func_0204A39C(s->f8[i], b, 0, d, &out);
    s->f4 = out / 0x48;
}
