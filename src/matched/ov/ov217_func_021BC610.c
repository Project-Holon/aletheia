/*
 * function: RESEARCH_LIST_VBlankHandler
 * address:  0x021BC610
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_LIST_VBlankHandler  0x021BC610  thumb  ov217
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25865.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void BG_SYS_Update();
extern void CLACT_VBlankSystem();
void RESEARCH_LIST_VBlankHandler(u32 a0, u32 a1)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj25865 *)((u8*)a1 + 0))->f98));
}

