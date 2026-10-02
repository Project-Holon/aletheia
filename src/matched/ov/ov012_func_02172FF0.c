/*
 * function: func_02172FF0
 * address:  0x02172FF0
 * packet:   pkt_ov012_02172FF0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02173D88  0x02173D88  thumb  ov012
 *   func_02173DBC  0x02173DBC  thumb  ov012
 */

typedef unsigned char u8;

extern int func_0203D1B4(void);
extern int func_02173D88(int a);
extern int func_02173DBC(int a);

void func_02172FF0(u8 *w)
{
    if (func_0203D1B4() > 1) {
        if (w[0x282D] != 0 && func_02173D88(w[0x282D]) == 1) {
            w[0x282D] = 0;
        }
        if (w[0x282C] != 0 && func_02173DBC(w[0x282C]) == 1) {
            w[0x282C] = 0;
        }
    } else {
        w[0x282D] = 0;
        w[0x282C] = 0;
    }
}
