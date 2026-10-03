/*
 * function: func_02175A34
 * address:  0x02175A34
 * packet:   pkt_ov011_02175A34
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02173DA0  0x02173DA0  thumb  ov011
 *   func_02173EEC  0x02173EEC  thumb  ov011
 *   func_021741E8  0x021741E8  thumb  ov011
 *   func_02173F74  0x02173F74  thumb  ov011
 *   func_021742EC  0x021742EC  thumb  ov011
 *   func_021742A8  0x021742A8  thumb  ov011
 */

typedef unsigned char u8;

extern int func_02173DA0(void *a, u8 *b, int i);
extern int func_02173EEC(void *a, u8 *b);
extern int func_021741E8(void *a, u8 *b);
extern int func_02173F74(void *a, u8 *b);
typedef unsigned int   u32;
extern u32 func_021742EC(u32 a);
extern int func_021742A8(int a);

void func_02175A34(void *a, u8 *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (b[0x194 + i] == 1 && func_02173DA0(a, b, i) == 1) {
            b[0x194 + i] = 0;
        }
    }
    if (b[0x19a] == 1 && func_02173EEC(a, b) == 1) {
        b[0x19a] = 0;
    }
    if (b[0x19b] == 1 && func_021741E8(a, b) == 1) {
        b[0x19b] = 0;
    }
    if (b[0x19c] == 1 && func_02173F74(a, b) == 1) {
        b[0x19c] = 2;
    }
    if (b[0x19f] != 0 && func_021742EC(b[0x19f]) == 1) {
        b[0x19f] = 0;
    }
    if (b[0x1a0] != 0 && func_021742A8(b[0x1a0]) == 1) {
        b[0x1a0] = 0;
    }
}
