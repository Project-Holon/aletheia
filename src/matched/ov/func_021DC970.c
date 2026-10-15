/*
 * function: BOX2_MAIN_VBlankHandler
 * address:  0x021DC970
 * packet:   pkt_021DC970
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_FlushDirtyBmpWins  0x021EAB04  thumb  ov170
 *   BG_SYS_Update  0x020419E4  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 */
#include "../include/Obj12145.h"
typedef unsigned char u8;
typedef unsigned int u32;

struct S02021D50;
extern void BOX2_SEQ_FlushDirtyBmpWins(unsigned char *w);
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

void BOX2_MAIN_VBlankHandler(u32 a, char *p)
{
    BOX2_SEQ_FlushDirtyBmpWins((unsigned char *)(((struct Obj12145 *)p)->f2C));
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)(*(u32 *)(((struct Obj12145 *)p)->f2C + 0x6c)));
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3ff8) |= 1;
}
