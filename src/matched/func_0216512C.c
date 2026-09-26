/*
 * function: func_0216512C
 * address:  0x0216512C
 * packet:   pkt_0216512C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:   wild=4
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 *
 * symbols:
 *   func_020273DC   0x020273DC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020273DC(void *, unsigned);

void func_0216512C(void *a0, unsigned a1)
{
    *(u16 *)((char *)a0 + 0x30) = 0x4;
    *(u16 *)((char *)a0 + 0x32) = a1;
    func_020273DC(a0, a1);
}

