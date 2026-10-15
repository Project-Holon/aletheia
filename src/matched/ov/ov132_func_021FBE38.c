/*
 * function: SCRIPT_COMMAND_CmdShowEntry
 * address: 0x021FBE38
 * packet: pkt_ov132_021FBE38
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACTING_GetSlot 0x021F9DB0 thumb ov132
 *   STA_ACTING_SetSlot 0x021F9DB8 thumb ov132
 *   STA_ACT_OBJ_FreeEntry 0x021F6B80 thumb ov112
 *   STA_ACT_LIGHT_SetElemVisible 0x021F6BC0 thumb ov112
 */
#include "../include/Obj14114.h"
#include "../include/Obj14115.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetActObj(void *);
extern unsigned int *STA_ACTING_GetSlot(void *,unsigned char);
typedef unsigned int   u32;
extern void STA_ACTING_SetSlot(void *p, void *v, u32 i);
extern void STA_ACT_OBJ_FreeEntry(unsigned int *,unsigned int *);
extern void STA_ACT_LIGHT_SetElemVisible(char *,unsigned int *,unsigned int);
int SCRIPT_COMMAND_CmdShowEntry(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct Obj14114 *)p)->f0;n=VM_GetU32(*(struct Cursor * *)&((struct Obj14114 *)p)->f4);ctx=STA_ACTING_GetActObj(((struct Obj14115 *)obj)->f34);STA_ACT_LIGHT_SetElemVisible(ctx,STA_ACTING_GetSlot(((struct Obj14115 *)obj)->f34,n),1);return 0; }
