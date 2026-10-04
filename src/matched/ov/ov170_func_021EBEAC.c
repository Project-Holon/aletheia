/*
 * function: func_021EBEAC
 * address: 0x021EBEAC
 * packet: pkt_ov170_021EBEAC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_021ED824 0x021ED824 thumb ov170
 *   func_021EC2A0 0x021EC2A0 thumb ov170
 *   func_021ED370 0x021ED370 thumb ov170
 *   func_021ECF78 0x021ECF78 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23996.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);extern void func_021ED824(char *);extern void func_021EC2A0(char *);extern void func_021ED370(unsigned char *);extern void func_021ECF78(char *);
void func_021EBEAC(unsigned char *p){((struct Obj23996 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f9E70=func_0204B100(180,0,76);func_021ED824(*(char * *)&((struct Obj00000 *)p)->f2C);func_021EC2A0(*(char * *)&((struct Obj00000 *)p)->f2C);func_021ED370(p);func_021ECF78(*(char * *)&((struct Obj00000 *)p)->f2C);}
