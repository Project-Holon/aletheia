/*
 * function: func_021FC490
 * address: 0x021FC490
 * packet: pkt_ov132_021FC490
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DF4 0x021F9DF4 thumb ov132
 *   func_021FAEA8 0x021FAEA8 thumb ov132
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 */
#include "../include/Obj06492.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void *func_021F9DD4(void *);
extern void *func_021F9DF4(void *p);
extern int func_021FAEA8(char *,void *);
extern void func_021F6EF4(void *,u32 *,const u32 *);
extern void func_021FADF8(char *,char *);
void func_021FC490(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DD4(((struct Obj06492 *)p)->f8); func_021F9DF4(((struct Obj06492 *)p)->f8); result=func_021FAEA8(p+8,pos); func_021F6EF4(ctx,*(u32 * *)&((struct Obj06492 *)p)->f4,(u32 *)pos); if(result==1) func_021FADF8(*(char * *)&((struct Obj06492 *)p)->f28,*(char * *)&((struct Obj06492 *)p)->f2C); }
