/*
 * function: func_021DBD40
 * address: 0x021DBD40
 * packet: pkt_ov183_021DBD40
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021FD744 0x021FD744 thumb ov186
 */
#include "../include/Obj00050.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void func_021DCE28(char *,char *),func_021DCE48(char *,char *),func_021DD054(char *,char *);
extern int func_021FD744(int *a);
void func_021DBD40(int *task,int b,char *p) { if(((struct Obj00050 *)p)->fB0) func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0); else func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0); func_021DD054(p,*(char * *)&((struct Obj00050 *)p)->fD0); func_021FD744(task); }
