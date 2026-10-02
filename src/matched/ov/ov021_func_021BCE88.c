/*
 * function: func_021BCE88
 * address:  0x021BCE88
 * packet:   pkt_ov021_021BCE88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_021BC92C  0x021BC92C  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned short u16;

extern void func_021BCB9C(char *p, int a);
extern void func_02040588(int a, int b);
extern void func_021BC92C(char *p);

void func_021BCE88(char *p)
{
    if (*(u16 *)(p + 0x42) > 0x14) {
        func_021BCB9C(p, 0);
        func_02040588(3, 0);
        func_021BC92C(p);
    }
}
