/*
 * function: func_0220B4EC
 * address:  0x0220B4EC
 * packet:   pkt_0220B4EC
 * region:   ov207
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
extern int func_0204B100(int, int, int);
extern void func_0204B270(void);
extern void func_020434DC(int, int);
extern void func_02043598(int, int);

void func_0220B4EC(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C(0x0220BACC, a, b);
    *(int *)p = func_0204B100(0x80, 0, b);
    func_0204B270();
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
