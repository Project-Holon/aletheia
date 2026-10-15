/*
 * function: LIVEBATTLEMATCH_IRC_ShowMenu
 * address: 0x0217DEA4
 * packet: pkt_ov176_0217DEA4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DrawStatusWindow 0x021E5F24 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DrawDateWindow 0x021E62CC thumb ov177
 */
#include "../include/Obj00348.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_VIEW_DrawStatusWindow(char *,int,void *,void *,int,u16);
extern void WIFIBATTLEMATCH_VIEW_DrawDateWindow(char *p, int mode, void *mgr, void *print, int font, u32 a5);
void LIVEBATTLEMATCH_IRC_ShowMenu(int *p, int a) {if(((struct Obj00348 *)p)->f14==0)WIFIBATTLEMATCH_VIEW_DrawStatusWindow(*(char * *)&((struct Obj00348 *)p)->f8,a,((struct Obj00348 *)p)->f0,((struct Obj00348 *)p)->f24,((struct Obj00348 *)p)->f1C,((struct Obj00348 *)p)->f34);else WIFIBATTLEMATCH_VIEW_DrawDateWindow(*(char * *)&((struct Obj00348 *)p)->f8,a,((struct Obj00348 *)p)->f0,((struct Obj00348 *)p)->f24,((struct Obj00348 *)p)->f1C,((struct Obj00348 *)p)->f34);}
