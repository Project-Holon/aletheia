/*
 * function: func_021B7F88
 * address: 0x021B7F88
 * packet: pkt_ov106_021B7F88
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B94B8 0x021B94B8 data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
extern char d_021B94B8[];
extern void func_02082BCC(void *, int, int);
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
void func_021B7F88(void **p, int a, int b) {
    func_02082BCC(p,0,0x14);
    func_0204A48C((const struct Cfg *)d_021B94B8,a,b);
    *p=func_0204B100(128,0,b);
    CLACT_SetUnitDefaultRenderer(*p);
    func_020434DC(16,1);
    func_02043598(16,1);
}
