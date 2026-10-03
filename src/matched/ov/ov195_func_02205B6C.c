/*
 * function: func_02205B6C
 * address:  0x02205B6C
 * packet:   pkt_02205B6C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(int, int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_02205B6C(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C(0x02208CB0, a, b);
    *(void **)p = func_0204B100(0x80, 0, b);
    func_0204B270(*(void **)p);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
