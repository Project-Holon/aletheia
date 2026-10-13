/*
 * function: func_021E560C
 * address:  0x021E560C
 * packet:   pkt_021E560C
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E8B10      0x021E8B10  data
 *   func_02082BCC   0x02082BCC  arm
 *   func_0204A48C   0x0204A48C  arm
 *   func_0204B100   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 *
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */


extern unsigned char d_021E8B10[];
extern void func_02082BCC(int, int, int);
typedef unsigned char  u8;
struct Bank;
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
typedef unsigned int   u32;
struct Bank;
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_021E560C(int *p, int b, int c)
{
    func_02082BCC((int)p, 0, 4);
    func_0204A48C((const struct Cfg *)d_021E8B10, b, c);
    p[0] = (int)func_0204B100(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
