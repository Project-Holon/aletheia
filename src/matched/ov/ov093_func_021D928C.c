/*
 * function: func_021D928C
 * address:  0x021D928C
 * packet:   pkt_ov093_021D928C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021D775C(int);
typedef unsigned int   u32;
extern int func_021D76BC(int key, u32 val);

void func_021D928C(int a, int b, int c, int d)
{
    if (b == func_021D775C(2) && b != func_021D775C(3)) {
        if (d == 8 || d == func_021D775C(0x1f)) {
            if (func_021D775C(0x20) < 0)
                *(int *)c = func_021D76BC(0x41, 1);
        }
    }
}
