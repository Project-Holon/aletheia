/*
 * function: WF2DMAP_SCENE_InitClact
 * address: 0x021D9838
 * packet: pkt_ov129_021D9838
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 */
#include "../include/Obj14057.h"

typedef struct  {
    unsigned words[7];
}
Config;
extern const Config gClActorInitParam;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
void WF2DMAP_SCENE_InitClact(char *p,unsigned a)  {
    Config c = gClActorInitParam;
    ((unsigned char *)&c)[8] = 16;
    ((unsigned char *)&c)[9] = 112;
    CLACT_InitSystem((const struct Cfg *)(&c),a,50);
    BG_SYS_SetMainPlaneVisible(16,1);
    ((struct Obj14057 *)p)->f25C=CLACT_CreateUnit(64,0,50);
    CLACT_SetUnitDefaultRenderer(((struct Obj14057 *)p)->f25C);
}
