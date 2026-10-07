/*
 * function: func_021623DC
 * address: 0x021623DC
 * packet: pkt_ov010_021623DC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02162530 0x02162530 thumb ov010
 */
#include "../../../matched/include/Obj04155.h"
typedef unsigned short u16;
extern void func_02162530(char *);
typedef struct { unsigned char pad[0x3f]; unsigned char low:7; unsigned char flag:1; } Flags;
void func_021623DC(char *p) { func_02162530(p); *(char * *)&((struct Obj04155 *)p)->f120=p+0x2328; ((struct Obj04155 *)p)->f34=0; ((Flags *)p)->flag=0; }
