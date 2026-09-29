/*
 * function: func_021B8600
 * address:  0x021B8600
 * packet:   pkt_ov070_021B8600
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B97CC  0x021B97CC  thumb  ov070
 *   func_02021D50  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 */

extern void func_021B97CC();
extern void func_02021D50();
extern void func_0204A648();

void func_021B8600(int u, int p)
{
    int s = *(int *)((char *)p + 0x840);
    if (s == 1) {
        func_021B97CC(p, 1);
        *(int *)((char *)p + 0x840) = 0;
    } else if (s == 2) {
        func_021B97CC(p, 0);
        *(int *)((char *)p + 0x840) = 0;
    }
    func_02021D50(*(int *)((char *)p + 0x854));
    func_0204A648();
}
