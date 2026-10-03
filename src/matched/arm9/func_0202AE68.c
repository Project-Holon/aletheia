/*
 * function: func_0202AE68
 * address:  0x0202AE68
 * packet:   pkt_0202AE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202AE9C (thumb, from name) has no witness outside 0202AE68..0202AE9A. Every concrete byte reproduces.
 * status:   EXACT
 */

typedef unsigned int u32;

extern int func_0202AD8C(void *obj);
extern int func_0202AE9C(void *obj);
extern int func_0202AE64(void *obj);
extern void func_0202AEB8(void *obj, u32 value);

int func_0202AE68(void *obj)
{
    int v;

    if (func_0202AD8C(obj) == 0) {
        return 0;
    }
    v = func_0202AE9C(obj);
    if (v == func_0202AE64(obj)) {
        return 0;
    }
    func_0202AEB8(obj, v);
    return 1;
}
