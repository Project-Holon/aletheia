/*
 * function: WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream
 * address: 0x021D80CC
 * packet: pkt_ov116_021D80CC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 */
#include "../include/Obj06418.h"

typedef unsigned int u32;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *p) {
 int v;
 if(((struct Obj06418 *)p)->f9A4==0) return 1;
 v=PRINTSYS_PrintStreamGetState(((struct Obj06418 *)p)->f9A4);
 if(v==2) { PRINTSYS_PrintStreamDelete(((struct Obj06418 *)p)->f9A4); ((struct Obj06418 *)p)->f9A4=0; return 1; }
 if(v==1) { if(KEY_GetTrg()==1 || TOUCHPANEL_GetTrg()!=0) PRINTSYS_PrintStreamReleasePause(((struct Obj06418 *)p)->f9A4); }
 return 0;
}
