/*
 * function: func_021EA75C
 * address:  0x021EA75C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF32C  0x021EF32C  thumb  ov170
 *   func_021EC688  0x021EC688  thumb  ov170
 *
 * Stop one 0x74 sub-object, then the plain stop.
 */



struct WinMgr;
extern void func_021EF32C(struct WinMgr *mgr);
extern void func_021EC688(int);
void func_021EA75C(int p)
{
    func_021EF32C(*(struct WinMgr **)(*(int *)(p + 0x2c) + 0x74));
    func_021EC688(p);
}
