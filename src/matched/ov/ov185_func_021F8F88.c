/*
 * function: BR_POKESEARCH_CreateMsgbox
 * address: 0x021F8F88
 * packet: pkt_ov185_021F8F88
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 */
#include "../include/Obj06624.h"
#include "../include/Obj14448.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
void BR_POKESEARCH_CreateMsgbox(char *p, int *q) { if(!((struct Obj06624 *)p)->f4)((struct Obj06624 *)p)->f4=BR_UTIL_CreateTextWin((int)(((struct Obj14448 *)q)->fC),(void *)(((struct Obj06624 *)p)->f2C),((struct Obj06624 *)p)->f30);BR_UTIL_SetWindowText(((struct Obj06624 *)p)->f4,((struct Obj14448 *)q)->fC,(void *)0x146); }
