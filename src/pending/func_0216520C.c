/*
 * function: func_0216520C
 * address:  0x0216520C
 * packet:   pkt_0216520C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:   wild=4
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 *
 * symbols:
 *   func_02027414   0x02027414  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02027414(void *, unsigned);

void func_0216520C(void *a0, unsigned a1)
{
    *(u16 *)((char *)a0 + 0x30) = 0x8;
    *(u16 *)((char *)a0 + 0x34) = a1;
    func_02027414(a0, a1);
}

