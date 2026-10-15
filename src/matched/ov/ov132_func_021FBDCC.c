/*
 * function: SCRIPT_COMMAND_CmdAddEntry
 * address: 0x021FBDCC
 * packet: pkt_ov132_021FBDCC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACT_OBJ_AddEntry 0x021F6B18 thumb ov112
 *   STA_ACTING_SetSlot 0x021F9DB8 thumb ov132
 */
#include "../include/Obj10555.h"
#include "../include/Obj14112.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
struct Object; struct Entry;
extern void *STA_ACTING_GetActObj(void *p);
extern struct Entry *STA_ACT_OBJ_AddEntry(struct Object *,unsigned short);
typedef unsigned int   u32;
extern void STA_ACTING_SetSlot(void *p, void *v, u32 i);
int SCRIPT_COMMAND_CmdAddEntry(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char * *)&((struct Obj10555 *)p)->f0;a=VM_GetU32(*(struct Cursor * *)&((struct Obj10555 *)p)->f4);b=VM_GetU32(*(struct Cursor * *)&((struct Obj10555 *)p)->f4);entry=STA_ACT_OBJ_AddEntry(STA_ACTING_GetActObj(((struct Obj14112 *)obj)->f34),b);STA_ACTING_SetSlot(((struct Obj14112 *)obj)->f34,entry,(unsigned char)a);return 0; }
