/*
 * function: func_021BE614
 * address:  0x021BE614
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BE630  0x021BE630  thumb  ov217
 *   func_021BF594  0x021BF594  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020061E4();
extern void func_021BE630(u8 *, u32);
extern void func_021BF594(char *p, int i);
u32 func_021BE614(u32 a0, u32 a1)
{
    func_021BE630((u8 *)a0, a1);
    func_021BF594((char *)a0, 1);
    return func_020061E4(1352);
}

