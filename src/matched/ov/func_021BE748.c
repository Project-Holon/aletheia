/*
 * function: func_021BE748
 * address:  0x021BE748
 * packet:   pkt_021BE748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Unblocked: the bl to func_02047674 (0x02047674, an unlabelled ARM leaf
 * getter emitted as data words) is now attested `matched` by the arm9
 * source src/matched/func_02047674.c.  The listing extent still runs two
 * bytes long to the next label, hence EXACT*.
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
extern int func_02047674(int p);

int func_021BE748(u32 a)
{
return ((*(u16 *)((u8 *)(*(u32 *)((u8 *)(func_02047674(*(u32 *)((u8 *)(a) + 12))) + 8)) + 4) << 12) - (1 << 12));
}

