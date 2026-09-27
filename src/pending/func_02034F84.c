/*
 * function: func_02034F84
 * address:  0x02034F84
 * packet:   pkt_02034F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   d_021469BC   0x021469BC  data  a4
 *   func_02034F74 0x02034F74 arm
 *
 * byte-correct (28 bytes) but capped at MATCH: the tail-call target
 * 0x02034F74 is an unlabelled leaf accessor (no lr-save, so disasm.py never
 * traced a func_ start there; its only reference image-wide is this
 * wrapper's own pool word).  Waiting on a layout/function_starts.txt seed
 * for 0x02034F74, which is the integrator's file.
 */

typedef unsigned int u32;

extern u32 d_021469BC[];
extern void func_02034F74(void *p, u32 v);

void func_02034F84(u32 v)
{
    func_02034F74((void *)d_021469BC[0], v);
}
