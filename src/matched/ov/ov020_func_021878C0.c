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
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_020414AC  0x020414AC  arm
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
void func_0203F8F4(u16 heapId);
void func_0203FC28(struct DispConfig *cfg);
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
void func_0204047C(int idx, unsigned short val);
void func_020414AC(int a);

void EL_SCOREBOARD_SetupStandaloneDisplay(char *o)
{
    BG_SYS_SetVramBanks((const struct DispVram *)EL_SCOREBOARD_VramBankConfig);
    func_0203F8F4(((struct Obj19478 *)o)->f8);
    func_0203FC28((struct DispConfig *)EL_SCOREBOARD_DispConfig);
    func_0203FCA0(3, (const struct BgTemplate *)EL_SCOREBOARD_BgTemplate, 0);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}
