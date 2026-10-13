/*
 * function: PMSIV_CATEGORY_CreateCursor
 * address: 0x021BB61C
 * packet: pkt_ov110_021BB61C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj03240.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int a,b,c; } Triple;
extern void PMS_INPUT_VIEW_GetUiRes(void *,Triple *,int,int);
struct Obj;
extern struct Obj *PMS_INPUT_VIEW_CreateActor(char *p, u32 *r, short x, short y, u32 a, int mode);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void PMSIV_CATEGORY_CreateCursor(u8 *p) { Triple t; PMS_INPUT_VIEW_GetUiRes(((struct Obj03240 *)p)->f0,&t,0,0); ((struct Obj03240 *)p)->f54=PMS_INPUT_VIEW_CreateActor(((struct Obj03240 *)p)->f0,(u32 *)(&t),48,64,3,1); CLACT_SetActorAnimSeq(((struct Obj03240 *)p)->f54,4); CLACT_SetActorDrawEnable(((struct Obj03240 *)p)->f54,0); }
