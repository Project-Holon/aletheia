/*
 * function: ITEMMENU_LeaveQuantityMode
 * address: 0x021BB0BC
 * packet: pkt_ov070_021BB0BC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   ITEMMENU_PrintPocketCount 0x021BAF38 thumb ov070
 */
#include "../include/Obj06179.h"
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void ITEMMENU_PrintPocketCount(int, int);
void ITEMMENU_LeaveQuantityMode(char *p) { CLACT_SetActorDrawEnable(((struct Obj06179 *)p)->f710, 1); CLACT_SetActorDrawEnable(((struct Obj06179 *)p)->f714, 1); BMP_WIN_ClearScreen(((struct Obj06179 *)p)->f764); BMP_WIN_ClearScreen(((struct Obj06179 *)p)->f75C); ITEMMENU_PrintPocketCount((int)p, ((struct Obj06179 *)p)->f80C); }
