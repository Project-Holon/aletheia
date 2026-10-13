/*
 * function: ITEMMENU_EnterQuantityMode
 * address: 0x021BB08C
 * packet: pkt_ov070_021BB08C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   ITEMMENU_PrintMoney 0x021BAFC4 thumb ov070
 */
#include "../include/Obj09883.h"
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
typedef unsigned char  u8;
extern void ITEMMENU_PrintMoney(u8 *p);
void ITEMMENU_EnterQuantityMode(char *p) { CLACT_SetActorDrawEnable(((struct Obj09883 *)p)->f710, 0); CLACT_SetActorDrawEnable(((struct Obj09883 *)p)->f714, 0); BMP_WIN_ClearScreen(((struct Obj09883 *)p)->f504); ITEMMENU_PrintMoney((u8 *)p); }
