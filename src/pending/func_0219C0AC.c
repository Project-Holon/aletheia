/*
 * function: func_0219C0AC
 * address:  0x0219C0AC
 * packet:   pkt_0219C0AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_0216DA50 at +0014 of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216DA7C  0x0216DA7C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216DA50(u32);
extern u32 func_0216DA7C(u32);
extern u32 func_02197EDC(u32, u32, u32, u32);

int func_0219C0AC(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC(a, b, c, d) == 0) {
    return 0;
}
func_0216DA50(a);
func_0216DA7C(a);
*(u8 *)((u8 *)(b)) = 2;
return 0;
}

