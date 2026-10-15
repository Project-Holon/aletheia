/*
 * function: WF2DMAP_SCENE_StepUpdate
 * address: 0x021D8C5C
 * packet: pkt_ov129_021D8C5C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WF2DMAP_SCENE_ProcessPending 0x021D9760 thumb ov129
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   WF2DMAP_SCENE_HandleInput 0x021D8FA0 thumb ov129
 */
#include "../include/Obj00361.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern unsigned WIPE_SYS_EndCheck(void);
extern void WF2DMAP_SCENE_ProcessPending(char *);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void WF2DMAP_SCENE_HandleInput(char *);
int WF2DMAP_SCENE_StepUpdate(char *p) {if(((struct Obj00361 *)p)->f234==0){if(WIPE_SYS_EndCheck()==1)((struct Obj00361 *)p)->f234+=1;}else {WF2DMAP_SCENE_ProcessPending(p);BUTTON_MAN_UpdateSlots(((struct Obj00361 *)p)->f294);WF2DMAP_SCENE_HandleInput(p);}return 0;}
