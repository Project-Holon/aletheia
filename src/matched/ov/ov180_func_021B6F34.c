/*
 * function: HALL_OF_FAME_StateSetupTrainerScene
 * address: 0x021B6F34
 * packet: pkt_ov180_021B6F34
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword alignment padding at 0x021B6F7E.
 * symbols:
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   HALL_OF_FAME_SetVramBanks 0x021B61D4 thumb ov180
 *   HALL_OF_FAME_SetupDisplay 0x021B6224 thumb ov180
 *   HALL_OF_FAME_InitBackgrounds 0x021B6254 thumb ov180
 *   HALL_OF_FAME_LoadBackgroundGraphics 0x021B6360 thumb ov180
 *   HALL_OF_FAME_Init3d 0x021B66A0 thumb ov180
 *   HALL_OF_FAME_InitMcss 0x021B68A8 thumb ov180
 *   HALL_OF_FAME_InitActorSystem 0x021B7318 thumb ov180
 *   HALL_OF_FAME_CreateTrainerSceneObjects 0x021B7D80 thumb ov180
 *   HALL_OF_FAME_AddVBlankTaskTrainer 0x021B6170 thumb ov180
 *   HALL_OF_FAME_BeginFadeIn 0x021B7210 thumb ov180
 */
#include "../include/Obj00547.h"
typedef unsigned int   u32;
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void HALL_OF_FAME_SetVramBanks(int);
extern void HALL_OF_FAME_SetupDisplay(void);
extern void HALL_OF_FAME_InitBackgrounds(void);
extern void HALL_OF_FAME_LoadBackgroundGraphics(void);
extern void HALL_OF_FAME_Init3d(char *);
extern void HALL_OF_FAME_InitMcss(char *);
extern void HALL_OF_FAME_InitActorSystem(char *,int);
extern void HALL_OF_FAME_CreateTrainerSceneObjects(char *);
extern void HALL_OF_FAME_AddVBlankTaskTrainer(int *p);
extern int HALL_OF_FAME_BeginFadeIn(char *,int);
int HALL_OF_FAME_StateSetupTrainerScene(char *p) {
    BG_SYS_SetLcdSwap(0); HALL_OF_FAME_SetVramBanks(1); HALL_OF_FAME_SetupDisplay(); HALL_OF_FAME_InitBackgrounds(); HALL_OF_FAME_LoadBackgroundGraphics();
    HALL_OF_FAME_Init3d(p); HALL_OF_FAME_InitMcss(p); HALL_OF_FAME_InitActorSystem(p,1); HALL_OF_FAME_CreateTrainerSceneObjects(p); HALL_OF_FAME_AddVBlankTaskTrainer((int *)p);
    ((struct Obj00547 *)p)->f8=2;
    return HALL_OF_FAME_BeginFadeIn(p,8);
}
