/*
 * function: HALL_OF_FAME_ExitActorSystem
 * address: 0x021B7390
 * packet: pkt_ov180_021B7390
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
#include "../include/Obj04569.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void BMP_OAM_DeleteSys(void *);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void HALL_OF_FAME_ExitActorSystem(char *p){BMP_OAM_DeleteSys(((struct Obj04569 *)p)->f911C);CLACT_DeleteUnit(((struct Obj04569 *)p)->f9044);CLACT_ExitSystem();}
