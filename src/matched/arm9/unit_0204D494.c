/*
 * function: func_0204D494, func_0204D4A4
 * address:  0x0204D494
 * packet:   pkt_0204D478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * unit:     yes
 * symbols:
 *   func_02064384  0x02064384  arm
 *
 * Two identical tail calls to the same callee with the argument biased by
 * 0xc.  Unlabelled leaves; the range 0x0204D494..0x0204D4B4 is contiguous.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_02064384(u8 *p, u32 i);

void func_0204D494(u8 *a0, u32 i)
{
    func_02064384(a0 + 0xc, i);
}

void func_0204D4A4(u8 *a0, u32 i)
{
    func_02064384(a0 + 0xc, i);
}
