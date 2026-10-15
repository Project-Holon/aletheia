/*
 * function: RESEARCH_GRAPH_TransferPalettes
 * address:  0x021BF6BC
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
 *   RESEARCH_GRAPH_TransferPalettes  0x021BF6BC  thumb  ov217
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25930.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALANM_TransferPalettes();
extern u32 func_020419E4();
extern void CLACT_VBlankSystem(void);
u32 RESEARCH_GRAPH_TransferPalettes(u32 a0, u32 a1)
{
    func_020419E4();
    CLACT_VBlankSystem();
    return PALANM_TransferPalettes(((struct Obj25930 *)(((u8*)a1)))->f3B8);
}

