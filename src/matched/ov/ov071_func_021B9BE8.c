/*
 * function: MONOLITH_TOOL_CreateScrollArrows
 * address: 0x021B9BE8
 * packet: pkt_ov071_021B9BE8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7118 0x021B7118 thumb ov071
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj02123.h"
#include "../include/Obj07705.h"

struct Obj;
extern struct Obj *func_021B7118(int *p, int x, int y, int w);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void MONOLITH_TOOL_CreateScrollArrows(char *p, char *q) { ((struct Obj07705 *)q)->f18 = func_021B7118(((struct Obj02123 *)p)->f4, 0x80, 0x1c, 9); ((struct Obj07705 *)q)->f1C = func_021B7118(((struct Obj02123 *)p)->f4, 0x80, 0xa4, 10); CLACT_SetActorDrawEnable(((struct Obj07705 *)q)->f18, 0); CLACT_SetActorDrawEnable(((struct Obj07705 *)q)->f1C, 0); }
