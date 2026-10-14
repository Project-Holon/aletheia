/*
 * function: ZUKAN_LIST_ScrollByDelta
 * address: 0x021BCC2C
 * packet: pkt_ov209_021BCC2C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_ScrollActorsBy 0x021BE34C thumb ov209
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   ZUKAN_LIST_MoveCursorActor 0x021BE51C thumb ov209
 *   ZUKAN_LIST_UpdateArrowActors 0x021BE5D4 thumb ov209
 */
#include "../include/Obj00088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void ZUKAN_LIST_ScrollActorsBy(char *,int),ZUKAN_LIST_MoveCursorActor(char *,int),ZUKAN_LIST_UpdateArrowActors(char *,int);extern int FRAME_LIST_GetCursor(char *);
void ZUKAN_LIST_ScrollByDelta(char *p,int delta) { ZUKAN_LIST_ScrollActorsBy(p,(signed char)-delta);ZUKAN_LIST_MoveCursorActor(p,FRAME_LIST_GetCursor(*(char * *)&((struct Obj00088 *)p)->fC2C));ZUKAN_LIST_UpdateArrowActors(p,1); }
