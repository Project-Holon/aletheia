/*
 * function: BR_CODEIN_HideMenuText
 * address: 0x021E2FE8
 * packet: pkt_ov183_021E2FE8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 */
#include "../include/Obj06616.h"
#include "../include/Obj24695.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void BR_UTIL_StartEffect(char *,u32,const struct Pair *);
extern void BR_UTIL_DeleteTextWin(void *,int);
void BR_CODEIN_HideMenuText(char *p) { int zero=0;BR_UTIL_StartEffect(*(char * *)&((struct Obj06616 *)p)->f30,0,0);if(((struct Obj06616 *)p)->f8){BR_UTIL_DeleteTextWin(((struct Obj06616 *)p)->f8,((struct Obj24695 *)(*(char * *)&((struct Obj06616 *)p)->f3C))->f8);*(int *)&((struct Obj06616 *)p)->f8=zero;} }
