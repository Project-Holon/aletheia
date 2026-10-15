/*
 * function: BR_CODEIN_DeleteMenuButtons
 * address: 0x021E31AC
 * packet: pkt_ov183_021E31AC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 */
#include "../include/Obj10763.h"
#include "../include/Obj10764.h"
#include "../include/Obj14446.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void BR_UTIL_DeleteTextWin(void *,int);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(char *,unsigned);
void BR_CODEIN_DeleteMenuButtons(char *p,char *q) { int i;char *s;if(((struct Obj10763 *)p)->f8){BR_UTIL_DeleteTextWin(((struct Obj10763 *)p)->f8,*(int *)&((struct Obj14446 *)q)->f8);*(int *)&((struct Obj10763 *)p)->f8=0;}for(i=0;i<4;i++){s=p+i*4;if(((struct Obj10764 *)s)->f14){BR_BTN_DeleteObject(((struct Obj10764 *)s)->f14);((struct Obj10764 *)s)->f14=0;}}BR_RES_ReleaseSprite(*(char * *)&((struct Obj14446 *)q)->f8,1); }
