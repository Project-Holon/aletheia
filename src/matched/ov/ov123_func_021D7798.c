/*
 * function: GSYNC_STATE_StateMusicalSaveApply
 * address: 0x021D7798
 * packet: pkt_ov123_021D7798
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_DIST_SAVE_ProcessApply 0x0200C5F8 thumb
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateCleanupDownload 0x021D751C thumb ov123
 */
#include "../include/Obj10445.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MusicalDist;
extern u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateCleanupDownload(int a);
void GSYNC_STATE_StateMusicalSaveApply(u8 *p) { if(MUSICAL_DIST_SAVE_ProcessApply(((struct Obj10445 *)p)->f30)) { p[174]=0; ((struct Obj10445 *)p)->f30=0; GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateCleanupDownload,0x38e); } }
