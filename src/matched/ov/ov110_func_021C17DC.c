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
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021C3A28 0x021C3A28 data a4
 */
extern const unsigned d_021C3A28[];
extern void func_02082BCC(void *, int, unsigned);
extern void func_0204A48C(const void *, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
void func_021C17DC(void **p, unsigned arg, unsigned heap) {
    func_02082BCC(p, 0, 4);
    func_0204A48C(d_021C3A28, arg, heap);
    *p = func_0204B100(128, 0, heap);
    func_0204B270(*p);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}
