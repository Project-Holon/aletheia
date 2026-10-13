/*
 * function: func_021C17DC
 * address: 0x021C17DC
 * packet: pkt_ov110_021C17DC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021C3A28 0x021C3A28 data a4
 */
extern const unsigned d_021C3A28[];
extern void func_02082BCC(void *, int, unsigned);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
void func_021C17DC(void **p, unsigned arg, unsigned heap) {
    func_02082BCC(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)d_021C3A28, arg, heap);
    *p = CLACT_CreateUnit(128, 0, heap);
    CLACT_SetUnitDefaultRenderer(*p);
    func_020434DC(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}
