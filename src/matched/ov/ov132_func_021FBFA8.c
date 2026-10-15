/*
 * function: SCRIPT_COMMAND_CmdSetAnimSlot
 * address: 0x021FBFA8
 * packet: pkt_ov132_021FBFA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Own 021F9EDC source takes u16; original caller passes the
 * full word b+0x33 without truncation, so the extern parameter is widened.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   STA_ACT_EFFECT_StartSystem 0x021F9EDC thumb ov132
 *   STA_ACTING_SetAnimSlot 0x021F9DCC thumb ov132
 */
#include "../include/Obj10557.h"
#include "../include/Obj14118.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetAnimHandle(void *p);
extern char *STA_ACT_EFFECT_StartSystem(char *,unsigned int);
typedef unsigned int   u32;
extern void STA_ACTING_SetAnimSlot(void *p, void *v, u32 i);
int SCRIPT_COMMAND_CmdSetAnimSlot(int unused,char *p) { char *obj; unsigned int a,b; char *entry;obj=*(char * *)&((struct Obj10557 *)p)->f0;a=VM_GetU32(*(struct Cursor * *)&((struct Obj10557 *)p)->f4);b=VM_GetU32(*(struct Cursor * *)&((struct Obj10557 *)p)->f4);entry=STA_ACT_EFFECT_StartSystem(STA_ACTING_GetAnimHandle(((struct Obj14118 *)obj)->f34),b+0x33);STA_ACTING_SetAnimSlot(((struct Obj14118 *)obj)->f34,entry,(unsigned char)a);return 0; }
