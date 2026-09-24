/*
 * function: func_021B1BE8
 * address:  0x021B1BE8
 * packet:   pkt_021B1BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_0215A5EC at +0002 of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0215A5EC(u32, u32, u32, u32);
extern u32 func_0216D9E4(u32);

int func_021B1BE8(u32 a, u32 b, u32 c, u32 d)
{
return func_0216D9E4(func_0215A5EC(a, b, c, d));
}

