/*
 * function: EVENTDATA_SYSTEM_Clear
 * address: 0x021623DC
 * packet: pkt_ov010_021623DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENTDATA_SYSTEM_ClearEventTables 0x02162530 thumb ov010
 */
#include "../include/Obj04155.h"
typedef unsigned short u16;
extern void EVENTDATA_SYSTEM_ClearEventTables(char *);
typedef struct { unsigned char pad[0x3f]; unsigned char low:7; unsigned char flag:1; } Flags;
void EVENTDATA_SYSTEM_Clear(char *p) { EVENTDATA_SYSTEM_ClearEventTables(p); *(char * *)&((struct Obj04155 *)p)->f120=p+0x2328; ((struct Obj04155 *)p)->f34=0; ((Flags *)p)->flag=0; }
