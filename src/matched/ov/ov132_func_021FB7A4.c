/*
 * function: SCRIPT_COMMAND_CmdLoadRankAnim
 * address: 0x021FB7A4
 * packet: pkt_ov132_021FB7A4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Original caller narrows both 021F9140 arguments to bytes,
 * overriding its own source's wider parameters; 021F9AD8 index is byte too.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_LoadRankAnim 0x021F9140 thumb ov132
 *   STA_ACTING_ScheduleActions 0x021F9AD8 thumb ov132
 */
#include "../include/Obj10553.h"
#include "../include/Obj14111.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void STA_ACTING_LoadRankAnim(unsigned char *,unsigned char,unsigned char);
extern void STA_ACTING_ScheduleActions(char *,int,unsigned char);
int SCRIPT_COMMAND_CmdLoadRankAnim(int unused,char *p) { char *obj; unsigned int index,n; obj=*(char * *)&((struct Obj10553 *)p)->f0;index=VM_GetU32(*(struct Cursor * *)&((struct Obj10553 *)p)->f4);n=VM_GetU32(*(struct Cursor * *)&((struct Obj10553 *)p)->f4);STA_ACTING_LoadRankAnim(*(unsigned char * *)&((struct Obj14111 *)obj)->f34,n,index);STA_ACTING_ScheduleActions(*(char * *)&((struct Obj14111 *)obj)->f34,1,index);return 0; }
