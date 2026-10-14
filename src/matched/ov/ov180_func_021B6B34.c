/*
 * function: HALL_OF_FAME_StateSetupMonScene
 * address: 0x021B6B34
 * packet: pkt_ov180_021B6B34
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_SetVramBanks 0x021B61D4 thumb ov180
 *   HALL_OF_FAME_SetupDisplay 0x021B6224 thumb ov180
 *   HALL_OF_FAME_Init3d 0x021B66A0 thumb ov180
 *   HALL_OF_FAME_InitParticleManager 0x021B6764 thumb ov180
 *   HALL_OF_FAME_InitParticleHeap 0x021B6750 thumb ov180
 *   HALL_OF_FAME_InitActorSystem 0x021B7318 thumb ov180
 *   HALL_OF_FAME_CreateMonSceneObjects 0x021B7CF0 thumb ov180
 *   HALL_OF_FAME_SetupBlendRegs 0x021B63E8 thumb ov180
 *   HALL_OF_FAME_AddVBlankTaskMon 0x021B6158 thumb ov180
 */
#include "../include/Obj00547.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void HALL_OF_FAME_SetVramBanks(int);
extern void HALL_OF_FAME_SetupDisplay(void);
extern void HALL_OF_FAME_Init3d(char *);
extern void HALL_OF_FAME_InitParticleManager(void);
extern void HALL_OF_FAME_InitParticleHeap(void);
extern void HALL_OF_FAME_InitActorSystem(char *,int);
extern void HALL_OF_FAME_CreateMonSceneObjects(char *);
extern void HALL_OF_FAME_SetupBlendRegs(void);
extern void HALL_OF_FAME_AddVBlankTaskMon(int *);
int HALL_OF_FAME_StateSetupMonScene(char *p){HALL_OF_FAME_SetVramBanks(0);HALL_OF_FAME_SetupDisplay();HALL_OF_FAME_Init3d(p);HALL_OF_FAME_InitParticleManager();HALL_OF_FAME_InitParticleHeap();HALL_OF_FAME_InitActorSystem(p,0);HALL_OF_FAME_CreateMonSceneObjects(p);HALL_OF_FAME_SetupBlendRegs();HALL_OF_FAME_AddVBlankTaskMon((int *)p);((struct Obj00547 *)p)->f8=1;return 5;}
