/*
 * function: SCRIPT_COMMAND_CmdFreeChar
 * address: 0x021FC22C
 * packet: pkt_ov132_021FC22C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   STA_ACT_LIGHT_DeleteActor 0x021F6EE4 thumb ov112
 *   STA_ACTING_SetCharSlot 0x021F9DE8 thumb ov132
 *   STA_ACTING_MarkDirty 0x021F95E8 thumb ov132
 */
#include "../include/Obj08169.h"
#include "../include/Obj14120.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetCharSystem(void *);
extern void *STA_ACTING_GetCharSlot(void *,u8);
extern void STA_ACT_LIGHT_DeleteActor(void *,u8 *);
extern void STA_ACTING_SetCharSlot(void *,void *,u8);
extern void STA_ACTING_MarkDirty(char *p);
int SCRIPT_COMMAND_CmdFreeChar(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct Obj14120 *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct Obj14120 *)p)->f4); ctx=STA_ACTING_GetCharSystem(((struct Obj08169 *)o)->f34); STA_ACT_LIGHT_DeleteActor(ctx,STA_ACTING_GetCharSlot(((struct Obj08169 *)o)->f34,a)); STA_ACTING_SetCharSlot(((struct Obj08169 *)o)->f34,0,a); STA_ACTING_MarkDirty(((struct Obj08169 *)o)->f34); return 0; }
