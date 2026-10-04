/*
 * function: func_021E5374
 * address: 0x021E5374
 * packet: pkt_ov170_021E5374
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021E8FE0 0x021E8FE0 thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E070C 0x021E070C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23902.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021ED6E4(char **,int);
extern void func_021EBA5C(char *,int);
extern void func_021DD14C(char *);
extern int func_021E8FE0(char *,int);
extern int func_021E8FC0(char *,int,int);
extern int func_021E070C(char *p);
void func_021E5374(u8 *p){func_021EF57C(*(struct WinMgr * *)&((struct Obj23902 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74);func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C,24);func_021DD14C((char *)p);func_021E8FC0((char *)p,(int)func_021E070C,func_021E8FE0((char *)p,44));}
