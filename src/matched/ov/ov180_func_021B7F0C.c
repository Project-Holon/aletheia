/*
 * function: HALL_OF_FAME_DeleteTrainerSceneObjects
 * address: 0x021B7F0C
 * packet: pkt_ov180_021B7F0C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_DeleteAllTextPlates 0x021B77C4 thumb ov180
 *   HALL_OF_FAME_DeleteAllActors 0x021B7604 thumb ov180
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   HALL_OF_FAME_ReleaseAllResources 0x021B756C thumb ov180
 */
#include "../include/Obj04569.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void HALL_OF_FAME_DeleteAllTextPlates(int *),HALL_OF_FAME_DeleteAllActors(int *);
extern void CLACT_DeleteRenderer(void *);
extern void HALL_OF_FAME_ReleaseAllResources(char *);
void HALL_OF_FAME_DeleteTrainerSceneObjects(int *p) { HALL_OF_FAME_DeleteAllTextPlates(p); HALL_OF_FAME_DeleteAllActors(p); CLACT_DeleteRenderer(((struct Obj04569 *)p)->f9118); HALL_OF_FAME_ReleaseAllResources((char *)p); }
