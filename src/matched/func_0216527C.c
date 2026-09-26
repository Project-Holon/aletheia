/*
 * function: func_0216527C
 * address:  0x0216527C
 * packet:   pkt_0216527C
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
 *   func_02027430   0x02027430  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02027430(void *, unsigned);

void func_0216527C(void *a0, unsigned a1)
{
    *(u16 *)((char *)a0 + 0x30) = 0xA;
    *(u16 *)((char *)a0 + 0x34) = a1;
    func_02027430(a0, a1);
}

