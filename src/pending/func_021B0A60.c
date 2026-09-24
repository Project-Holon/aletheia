/*
 * function: func_021B0A60
 * address:  0x021B0A60
 * packet:   pkt_021B0A60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_0215A614 at +0016 of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_0215A614  0x0215A614  thumb
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02159168(u32);
extern u32 func_0215A614(u32, u32);
extern u32 func_0215A61C(u32, u32, u32, u32);
extern u32 func_021912F8(u32);

int func_021B0A60(u32 a, u32 b, u32 c, u32 d)
{
if (func_021912F8(func_0215A61C(b, b, c, d)) == 1) {
    func_0215A614(b, 0);
    func_02159168(2);
    return 1;
}
return 0;
}

