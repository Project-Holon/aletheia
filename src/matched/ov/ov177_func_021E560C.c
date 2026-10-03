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
 *   func_0204B270   0x0204B270  arm
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 *
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */


extern unsigned char d_021E8B10[];
extern void func_02082BCC(int, int, int);
extern void func_0204A48C(void *, int, int);
extern int func_0204B100(int, int, int);
typedef unsigned int   u32;
struct Bank;
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_021E560C(int *p, int b, int c)
{
    func_02082BCC((int)p, 0, 4);
    func_0204A48C(d_021E8B10, b, c);
    p[0] = func_0204B100(0x80, 0, c);
    func_0204B270((void *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
