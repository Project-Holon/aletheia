/*
 * function: func_02193BC4
 * address:  0x02193BC4
 * packet:   pkt_02193BC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_02186764 at +0014 of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193EFC  0x02193EFC  thumb  ov021
 *   func_02186764  0x02186764  thumb
 *   func_02193EE8  0x02193EE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02186764(u32);
extern u32 func_02193EB4(u32, u32, u32, u32);
extern u32 func_02193EE8(u32);
extern u32 func_02193EFC(u32, u32);

int func_02193BC4(u32 a, u32 b, u32 c, u32 d)
{
func_02193EB4(a, b, c, d);
func_02186764((func_02193EFC(a, b) + 52));
return func_02193EE8(a);
}

