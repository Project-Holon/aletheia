/*
 * function: func_021D4294
 * address:  0x021D4294
 * packet:   pkt_021D4294
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  codegen shape only; both relocations (d_021F3B88 sole-ref/data
 * and func_0203D3A8 label) already resolve.  Original holds P in r3, adds
 * the pooled 0x3b1c into the pointer, and issues a real `blx` + `pop {r3,pc}`
 * (r3 pushed for 8-byte alignment).  Every spelling tried either allocates P
 * to r4 or makes the trailing call a tail `bx r3` with no frame.  A matching
 * source shape would be EXACT.
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data
 *   func_0203D3A8  0x0203D3A8  arm
 */

extern int d_021F3B88;
extern void func_0203D3A8(void *, int, int);

void func_021D4294(int a)
{
    unsigned short *p = (unsigned short *)(d_021F3B88 + 0x3b1c);

    p[0] = 0x64;
    p[1] = a;
    func_0203D3A8(*(void **)d_021F3B88, 0x100, 4);
}
