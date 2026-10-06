/*
 * function: func_021C9924
 * address:  0x021C9924
 * packet:   pkt_021C9924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Blocking site: the bl to func_02012EE4 at +0008 of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EE4  0x02012EE4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012EE4(u32, u32);

int func_021C9924(u32 a)
{
return func_02012EE4((u32)func_020120F4((const struct Ctx *)a), 0);
}

