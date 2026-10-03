/*
 * function: func_021EB744
 * address: 0x021EB744
 * packet: pkt_ov170_021EB744
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EB708 0x021EB708 thumb ov170
 */
struct WinMgr;
extern void func_021EB708(void *m, unsigned i, void *d);
void func_021EB744(char *p)
{
    func_021EB708(*(struct WinMgr **)(p + 0x74), 0, *(void **)(p + 0x104));
    func_021EB708(*(struct WinMgr **)(p + 0x74), 1, *(void **)(p + 0x10c));
    func_021EB708(*(struct WinMgr **)(p + 0x74), 2, *(void **)(p + 0x114));
    func_021EB708(*(struct WinMgr **)(p + 0x74), 3, *(void **)(p + 0x11c));
    func_021EB708(*(struct WinMgr **)(p + 0x74), 4, *(void **)(p + 0x124));
    func_021EB708(*(struct WinMgr **)(p + 0x74), 5, *(void **)(p + 0x12c));
}
