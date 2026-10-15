/*
 * function: func_021FC080
 * address: 0x021FC080
 * packet: pkt_ov132_021FC080
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetAnimSlot 0x021F9DC4 thumb ov132
 *   func_021F9FB4 0x021F9FB4 thumb ov132
 */
#include "../include/Obj10559.h"
#include "../include/Obj23259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetAnimSlot(void *,u8);
extern void func_021F9FB4(char *p, int i);
int func_021FC080(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct Obj10559 *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct Obj10559 *)p)->f4); b=VM_GetU32(*(struct Cursor * *)&((struct Obj10559 *)p)->f4); func_021F9FB4(STA_ACTING_GetAnimSlot(((struct Obj23259 *)o)->f34,a),(u16)b); return 0; }
