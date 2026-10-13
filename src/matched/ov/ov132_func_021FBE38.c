/*
 * function: func_021FBE38
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
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_021F6BC0 0x021F6BC0 thumb ov112
 */
#include "../include/Obj14114.h"
#include "../include/Obj14115.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void *func_021F9DAC(void *);
extern unsigned int *func_021F9DB0(void *,unsigned char);
typedef unsigned int   u32;
extern void func_021F9DB8(void *p, void *v, u32 i);
extern void func_021F6B80(unsigned int *,unsigned int *);
extern void func_021F6BC0(char *,unsigned int *,unsigned int);
int func_021FBE38(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct Obj14114 *)p)->f0;n=VM_GetU32(*(struct Cursor * *)&((struct Obj14114 *)p)->f4);ctx=func_021F9DAC(((struct Obj14115 *)obj)->f34);func_021F6BC0(ctx,func_021F9DB0(((struct Obj14115 *)obj)->f34,n),1);return 0; }
