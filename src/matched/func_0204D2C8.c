/*
 * function: func_0204D2C8
 * address:  0x0204D2C8
 * packet:   pkt_0204D18C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02082BCC   0x02082BCC  arm
 *
 * Unlabelled leaf after func_0204D224 in clact.c: clears the 0x7c-byte
 * animation sub-object (the same fill sub_0204D2DC ends with), as a tail
 * call.  Filed as the witness that turns func_0204D224's EXACT* into EXACT
 * once 0x0204D2C8 is seeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D2C8.c \
 *       --func func_0204D2C8 --addr 0x0204D2C8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void sub_02082BCC(void *dst, int value, u32 len);

void func_0204D2C8(void *anim)
{
    sub_02082BCC(anim, 0, 0x7c);
}
