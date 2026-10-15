/*
 * function: BEACON_VIEW_SetEntryVisible
 * address: 0x021F0EA4
 * packet: pkt_ov032_021F0EA4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BEACON_VIEW_SetEntryStatusVisible 0x021F0ED0 thumb ov032
 */
#include "../include/Obj00225.h"
extern void BMP_OAM_SetEnabled(unsigned char *,unsigned);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BEACON_VIEW_SetEntryStatusVisible(char *,int);
void BEACON_VIEW_SetEntryVisible(char *p,unsigned a) { BMP_OAM_SetEnabled(*(unsigned char * *)&((struct Obj00225 *)p)->f18,a); CLACT_SetActorDrawEnable(((struct Obj00225 *)p)->f10,a); CLACT_SetActorDrawEnable(((struct Obj00225 *)p)->fC,a); if(a==0) BEACON_VIEW_SetEntryStatusVisible(p,a); }
