/*
 * function: func_021E0B68
 * address:  0x021E0B68
 * packet:   pkt_ov093_021E0B68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021C815C(void *p);
extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);

void func_021E0B68(int a, void *b, int c)
{
    int n = 34;

    if (func_021C815C(b) == 0 || func_021C815C(b) == 3) {
        if (c == func_021D775C(2) && func_021D775C(n) == 0)
            func_021D76BC(n, 26);
    }
}
