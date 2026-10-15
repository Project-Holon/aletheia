/*
 * function: EL_SCOREBOARD_SetupStandaloneDisplay
 * address:  0x021878C0
 * packet:   pkt_ov020_021878C0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   EL_SCOREBOARD_VramBankConfig     0x02187E58  data  ov020
 *   EL_SCOREBOARD_DispConfig     0x02187E28  data  ov020
 *   EL_SCOREBOARD_BgTemplate     0x02187E38  data  ov020
 */
#include "../include/Obj19478.h"

typedef unsigned short u16;

extern char EL_SCOREBOARD_VramBankConfig[];
extern char EL_SCOREBOARD_DispConfig[];
extern char EL_SCOREBOARD_BgTemplate[];

typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
struct DispVram;
void BG_SYS_SetVramBanks(const struct DispVram *c);
void BG_SYS_Create(u16 heapId);
void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
void BG_SYS_FreeSlot(int a);

void EL_SCOREBOARD_SetupStandaloneDisplay(char *o)
{
    BG_SYS_SetVramBanks((const struct DispVram *)EL_SCOREBOARD_VramBankConfig);
    BG_SYS_Create(((struct Obj19478 *)o)->f8);
    BG_SYS_SetGraphicsMode((struct DispConfig *)EL_SCOREBOARD_DispConfig);
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)EL_SCOREBOARD_BgTemplate, 0);
    BG_SYS_SetVisibleLayer(0, 1);
    BG_SYS_SetVisibleLayer(3, 0);
    BG_SYS_SetVisibleLayer(1, 3);
    BG_SYS_SetVisibleLayer(2, 3);
    BG_SYS_FreeSlot(3);
}
