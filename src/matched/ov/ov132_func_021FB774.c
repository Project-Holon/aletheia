/*
 * function: SCRIPT_COMMAND_CmdClearSelection
 * address: 0x021FB774
 * packet: pkt_ov132_021FB774
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_SetSelection 0x021F95CC thumb ov132
 */
#include "../include/Obj08164.h"
#include "../include/Obj23256.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void STA_ACTING_SetSelection(char *,unsigned char,int);
int SCRIPT_COMMAND_CmdClearSelection(int unused,char *p) { char *obj; obj=*(char * *)&((struct Obj23256 *)p)->f0; STA_ACTING_SetSelection(*(char * *)&((struct Obj08164 *)obj)->f34,0,0);STA_ACTING_SetSelection(*(char * *)&((struct Obj08164 *)obj)->f34,1,0);STA_ACTING_SetSelection(*(char * *)&((struct Obj08164 *)obj)->f34,2,0);STA_ACTING_SetSelection(*(char * *)&((struct Obj08164 *)obj)->f34,3,0);return 0; }
