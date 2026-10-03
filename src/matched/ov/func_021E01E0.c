/*
 * function: func_021E01E0
 * address:  0x021E01E0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED918  0x021ED918  thumb  ov170
 *
 * Read status 9 from the p+0x2c+0x74 object, push frame -8, and
 *   return the status.
 */


typedef unsigned int u32;
struct WinMgr;
extern u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);
extern void func_021ED918(char *, int);
int func_021E01E0(char *p)
{
    int x = func_0202CDD4(*(struct WinMgr **)(*(int *)(p + 0x2c) + 0x74), 9);
    func_021ED918(p, -8);
    return x;
}
