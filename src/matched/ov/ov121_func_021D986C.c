/*
 * function: func_021D986C
 * address: 0x021D986C
 * packet: pkt_ov121_021D986C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DF5A8 0x021DF5A8 data a4
 *   d_021DF5C4 0x021DF5C4 data a4
 */
typedef unsigned int u32;
extern void func_02082BCC(void *, int, u32);
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
typedef unsigned char  u8;
struct Bank;
struct Obj;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern const u32 d_021DF5A8[];
extern const u32 d_021DF5C4[];
void func_021D986C(void **p, u32 a, u32 heap)
{
    void *q;
    func_02082BCC(p, 0, 8);
    func_0204A48C((const struct Cfg *)d_021DF5A8, a, heap);
    p[0] = func_0204B100(128, 0, heap);
    q = func_0204B034((unsigned char *)d_021DF5C4, 2, heap);
    p[1] = q;
    func_0204B258(p[0], q);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}
