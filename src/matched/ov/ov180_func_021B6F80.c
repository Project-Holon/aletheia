/*
 * function: HALL_OF_FAME_StateTeardownTrainerScene
 * address: 0x021B6F80
 * packet: pkt_ov180_021B6F80
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_RemoveVBlankTask 0x021B6188 thumb ov180
 *   HALL_OF_FAME_ExitActorSystem 0x021B7390 thumb ov180
 *   HALL_OF_FAME_Exit3d 0x021B66D4 thumb ov180
 *   HALL_OF_FAME_DeleteTrainerSceneObjects 0x021B7F0C thumb ov180
 *   HALL_OF_FAME_ExitBackgrounds 0x021B6340 thumb ov180
 *   HALL_OF_FAME_ExitMcss 0x021B6914 thumb ov180
 */
#include "../include/Obj04569.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void HALL_OF_FAME_RemoveVBlankTask(u8 *p);
extern void HALL_OF_FAME_ExitActorSystem(char *);
extern void HALL_OF_FAME_Exit3d(int *p);
extern void HALL_OF_FAME_DeleteTrainerSceneObjects(int *p);
extern void HALL_OF_FAME_ExitBackgrounds(void);
extern void HALL_OF_FAME_ExitMcss(int *);
int HALL_OF_FAME_StateTeardownTrainerScene(char *p){HALL_OF_FAME_RemoveVBlankTask((u8 *)p);HALL_OF_FAME_DeleteTrainerSceneObjects((int *)p);HALL_OF_FAME_ExitActorSystem(p);HALL_OF_FAME_ExitBackgrounds();HALL_OF_FAME_ExitMcss((int *)p);HALL_OF_FAME_Exit3d((int *)p);((struct Obj04569 *)p)->f8=0;return 1;}
