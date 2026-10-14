/*
 * function: HALL_OF_FAME_StateTeardownMonScene
 * address: 0x021B6B70
 * packet: pkt_ov180_021B6B70
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_RemoveVBlankTask 0x021B6188 thumb ov180
 *   HALL_OF_FAME_DeleteMonSceneObjects 0x021B7D44 thumb ov180
 *   HALL_OF_FAME_ExitActorSystem 0x021B7390 thumb ov180
 *   HALL_OF_FAME_ExitParticleHeap 0x021B675C thumb ov180
 *   HALL_OF_FAME_ExitParticleManager 0x021B6770 thumb ov180
 *   HALL_OF_FAME_Exit3d 0x021B66D4 thumb ov180
 */
#include "../include/Obj04569.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void HALL_OF_FAME_RemoveVBlankTask(u8 *p);
extern void HALL_OF_FAME_DeleteMonSceneObjects(int *);
extern void HALL_OF_FAME_ExitActorSystem(char *);
extern void HALL_OF_FAME_ExitParticleHeap(void);
extern void HALL_OF_FAME_ExitParticleManager(void);
extern void HALL_OF_FAME_Exit3d(int *p);
int HALL_OF_FAME_StateTeardownMonScene(char *p){HALL_OF_FAME_RemoveVBlankTask((u8 *)p);*(u16 *)0x04000050=0;*(u16 *)0x04001050=0;HALL_OF_FAME_DeleteMonSceneObjects((int *)p);HALL_OF_FAME_ExitActorSystem(p);HALL_OF_FAME_ExitParticleHeap();HALL_OF_FAME_ExitParticleManager();HALL_OF_FAME_Exit3d((int *)p);((struct Obj04569 *)p)->f8=0;return 7;}
