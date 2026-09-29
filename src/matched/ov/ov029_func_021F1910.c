/*
 * function: func_021F1910
 * address:  0x021F1910
 * packet:   pkt_ov029_021F1910
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B908  0x0204B908  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 */

extern void func_0204B908(int, int);
extern void func_0204B954(int, int);
extern void func_0204B92C(int, int);

void func_021F1910(char *p, int on)
{
    if (on) {
        func_0204B908(*(int *)(p + 0x150), 0);
        func_0204B954(*(int *)(p + 0x150), 0x2000);
        func_0204B92C(*(int *)(p + 0x150), 1);
    } else {
        func_0204B92C(*(int *)(p + 0x150), 0);
        func_0204B908(*(int *)(p + 0x150), 1);
    }
}
