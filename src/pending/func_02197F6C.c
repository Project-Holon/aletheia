/*
 * function: func_02197F6C
 * address:  0x02197F6C
 * packet:   pkt_02197F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_0216D7CC at +001C of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02163F10(u32);
extern u32 func_0216D5E0(u32, u32, u32, u32);
extern u32 func_0216D674(u32, u32);
extern u32 func_0216D7CC(u32);

int func_02197F6C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D5E0(a, ((b << 16) >> 16), c, d);
func_0216D674(a, 0);
func_02163F10(a);
return func_0216D7CC(a);
}

