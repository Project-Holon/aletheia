/*
 * function: func_021FBFDC
 * address: 0x021FBFDC
 * packet: pkt_ov132_021FBFDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   STA_ACTING_GetAnimSlot 0x021F9DC4 thumb ov132
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   STA_ACTING_SetAnimSlot 0x021F9DCC thumb ov132
 */
#include "../include/Obj10558.h"
#include "../include/Obj14119.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetAnimHandle(void *);
extern void *STA_ACTING_GetAnimSlot(void *,u8);
extern void func_021F9F58(u8 *,u8 *);
extern void STA_ACTING_SetAnimSlot(void *p, void *v, u32 i);
int func_021FBFDC(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct Obj14119 *)p)->f0; a=VM_GetU32(*(struct Cursor * *)&((struct Obj14119 *)p)->f4); ctx=STA_ACTING_GetAnimHandle(((struct Obj10558 *)o)->f34); func_021F9F58(ctx,STA_ACTING_GetAnimSlot(((struct Obj10558 *)o)->f34,a)); STA_ACTING_SetAnimSlot(((struct Obj10558 *)o)->f34,0,(u8)a); return 0; }
