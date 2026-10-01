/*
 * function: func_021ABD08
 * address:  0x021ABD08
 * packet:   pkt_ov021_021ABD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_021ABBA0  0x021ABBA0  thumb
 *   func_0207C768  0x0207C768  arm
 *   func_0218ED64  0x0218ED64  thumb
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x38];
    u16 h38;
    u16 h3a;
} S;

extern int func_021AB760(int a);
extern void func_021ABBA0(S *s, int c, int *y, int *x);
extern int func_0207C768(int x, int y);
extern void func_0218ED64(int h, u16 v);

/*
 * 2026-10-01: DIFF in one store position: the original keeps the
 * func_0207C768 result in r3, loads h38/h3a, then stores it to x's slot;
 * here the store comes before the two loads (separate statement and
 * assignment-in-expression both tried).
 */
void func_021ABD08(int a, S *s, int c)
{
    int h = func_021AB760(a);
    int y;
    int x;
    func_021ABBA0(s, c, &y, &x);
    func_0218ED64(h, s->h38 + (s->h3a - s->h38) * (x = func_0207C768(x, y)) / 0x1000);
}
