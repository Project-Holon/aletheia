/*
 * function: func_021FB738
 * address: 0x021FB738
 * packet: pkt_ov132_021FB738
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding follow the 58-byte body.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F95CC 0x021F95CC thumb ov132
 */
#include "../include/Obj14110.h"
#include "../include/Obj23255.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern int func_021FB1F4(char *,int);
extern void func_021F95CC(char *,unsigned char,int);
int func_021FB738(int unused,char *p) { char *obj; int mask; unsigned char i; obj=*(char * *)&((struct Obj14110 *)p)->f0; mask=func_021FB1F4(p,VM_GetU32(*(struct Cursor * *)&((struct Obj14110 *)p)->f4)); for(i=0;i<4;i++)if((1<<i)&mask)func_021F95CC(*(char * *)&((struct Obj23255 *)obj)->f34,i,1); return 0; }
