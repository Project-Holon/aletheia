/*
 * function: func_021EB7C8
 * address:  0x021EB7C8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EB6F0  0x021EB6F0  thumb  ov170
 *   func_021EB708  0x021EB708  thumb  ov170
 *
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */


struct WinMgr;
extern void func_021EB6F0(char *, int, int);
extern void func_021EB708(struct WinMgr *mgr, int, int);
void func_021EB7C8(char *p)
{
    func_021EB6F0(p, 0x17, 0x46);
    func_021EB708(*(struct WinMgr **)(*(int *)(p + 0x2c) + 0x74), 0xb,
                  *(int *)(*(int *)(p + 0x2c) + 0x14C));
}
