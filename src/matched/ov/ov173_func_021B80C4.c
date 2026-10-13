/*
 * function: func_021B80C4
 * address: 0x021B80C4
 * packet: pkt_ov173_021B80C4
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 */
#include "../include/Obj08266.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void APP_TASKMENU_WIN_SetDecide(char *,int);
int func_021B80C4(u8 *p,u16 n) {u8 *q;q=p+464;((struct Obj08266 *)q)->fA=1;((struct Obj08266 *)q)->f6=0;((struct Obj08266 *)q)->f8=n;APP_TASKMENU_WIN_SetDecide(*(char **)(p+((struct Obj08266 *)q)->f6*4+544),1);return 13;}
