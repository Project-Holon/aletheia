/*
 * function: func_021C38DC
 * address:  0x021C38DC
 * packet:   pkt_021C38DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_02012F98 at +000C of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02007C34(u32, u32);
extern u32 func_020120F4(u32);
extern u32 func_02012F98(u32);
extern u32 func_02188C80(u32, u32, u32, u32);

int func_021C38DC(u32 a, u32 b, u32 c, u32 d)
{
return func_02007C34(func_02012F98(func_020120F4(func_02188C80(a, b, c, d))), b);
}

