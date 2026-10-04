/*
 * function: func_021FBE64
 * address: 0x021FBE64
 * packet: pkt_ov132_021FBE64
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_021F6BC0 0x021F6BC0 thumb ov112
 */
#include "../include/Obj14116.h"
#include "../include/Obj14117.h"
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern void *func_021F9DAC(void *);
extern unsigned int *func_021F9DB0(void *,unsigned char);
typedef unsigned int   u32;
extern void func_021F9DB8(void *p, void *v, u32 i);
extern void func_021F6B80(unsigned int *,unsigned int *);
extern void func_021F6BC0(char *,unsigned int *,unsigned int);
int func_021FBE64(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct Obj14116 *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct Obj14116 *)p)->f4);ctx=func_021F9DAC(((struct Obj14117 *)obj)->f34);func_021F6BC0(ctx,func_021F9DB0(((struct Obj14117 *)obj)->f34,n),0);return 0; }
