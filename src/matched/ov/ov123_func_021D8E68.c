/*
 * function: GSYNC_STATE_StateTransferAnimationEffect
 * address: 0x021D8E68
 * packet: pkt_ov123_021D8E68
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_CreateEffectActorDefault 0x021D62A8 thumb ov123
 *   GSYNC_DISP_EnableActorAutoAnim 0x021D651C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateTransferAnimationOpen 0x021D8E28 thumb ov123
 */
#include "../include/Obj08114.h"
typedef unsigned char  u8;
extern void GSYNC_DISP_CreateEffectActorDefault(u8 *p);
extern void GSYNC_DISP_EnableActorAutoAnim(unsigned char *);
typedef unsigned int   u32;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateTransferAnimationOpen(char *p);
void GSYNC_STATE_StateTransferAnimationEffect(char *p) { if(--((struct Obj08114 *)p)->f60==0) { GSYNC_DISP_CreateEffectActorDefault(((struct Obj08114 *)p)->f14); GSYNC_DISP_EnableActorAutoAnim(((struct Obj08114 *)p)->f14); ((struct Obj08114 *)p)->f60=70; GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateTransferAnimationOpen,0x9e4); } }
