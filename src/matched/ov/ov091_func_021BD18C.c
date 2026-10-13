/*
 * function: PLIST_BATTLE_DeleteTeamPanel
 * address: 0x021BD18C
 * packet: pkt_ov091_021BD18C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_BATTLE_DeleteMiniCell 0x021BD454 thumb ov091
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj20920.h"
typedef unsigned char u8;
struct Descriptor;
extern void PLIST_BATTLE_DeleteMiniCell(char *,char *);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PLIST_BATTLE_DeleteTeamPanel(char *a,char *p) { u8 i; for(i=0;i<6;i++) { char *q=*(char **)(p+i*4+8); if(q)PLIST_BATTLE_DeleteMiniCell(a,q); } BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj20920 *)p)->f4); func_020307B0(p); }
