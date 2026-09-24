/*
 * function: func_021650BC
 * address:  0x021650BC
 * packet:   pkt_021650BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  the ABS32 pool word holds 0x020273C5, the thumb address of the arm9
 *           submitter at 0x020273C4, which no listing labels.  Same for the four
 *           siblings func_0216512C/0216519C/0216520C/0216527C (pool words
 *           0x020273DD/0x020273F9/0x02027415/0x02027431).  func_0216565C proves
 *           the shape: its pool word 0x0202744D resolves, so only the unlabelled
 *           arm9 addresses block these.  Promote when they get labels.
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 *
 * symbols:
 *   func_020273C4   0x020273C4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020273C4(void *, unsigned);

void func_021650BC(void *a0, unsigned a1)
{
    *(u16 *)((char *)a0 + 0x30) = 0x2;
    *(u16 *)((char *)a0 + 0x32) = a1;
    func_020273C4(a0, a1);
}

