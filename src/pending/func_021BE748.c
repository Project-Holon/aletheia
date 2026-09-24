/*
 * function: func_021BE748
 * address:  0x021BE748
 * packet:   pkt_021BE748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*: every concrete byte reproduces; the single relocation below keeps its wildcard
 * 
 * Blocking site: the bl to func_02047674 at +0004 of this function.
 * 
 * the ARM9 listing emits the bytes at this address as data words, so disasm.py never traced the tiny function that lives there and no manifest entry covers it.  There is no label to witness and no region hint to give, and the address is outside this overlay's own window, so this lane cannot file the target.  Filing an arm9 source for the TARGET (rule 10) would attest the caller with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02047674  0x02047674  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02047674(u32, u32, u32, u32);

int func_021BE748(u32 a, u32 b, u32 c, u32 d)
{
return ((*(u16 *)((u8 *)(*(u32 *)((u8 *)(func_02047674(*(u32 *)((u8 *)(a) + 12), b, c, d)) + 8)) + 4) << 12) - (1 << 12));
}

