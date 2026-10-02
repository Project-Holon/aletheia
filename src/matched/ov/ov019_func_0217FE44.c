/*
 * function: func_0217FE44
 * address:  0x0217FE44
 * packet:   pkt_ov019_0217FE44
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   d_02180794     0x02180794  data  ov019  a4
 *   d_0218079C     0x0218079C  data  ov019  a4
 */

typedef short s16;

extern int func_02188CB4(int);
extern int func_021A3074(int);
extern int func_0216D83C(int);
extern int func_0216D86C(int);
extern s16 d_02180794[][2];
extern s16 d_0218079C[][2];

int func_0217FE44(int a, int mode, unsigned *out)
{
    unsigned i;
    int x;
    int y;
    int h;

    h = func_02188CB4(a);
    *out = 0;
    y = func_021A3074(h);
    x = func_0216D83C(y);
    y = func_0216D86C(y);
    if (mode == 2) {
        for (i = 0; i < 2; i++) {
            if (d_02180794[i][0] == x && d_02180794[i][1] == y) {
                *out = i;
                return 1;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (d_0218079C[i][0] == x && d_0218079C[i][1] == y) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}
