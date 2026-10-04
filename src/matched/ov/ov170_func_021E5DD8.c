/*
 * function: func_021E5DD8
 * address: 0x021E5DD8
 * packet: pkt_ov170_021E5DD8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EBA5C(char *,int);
extern void func_021DD14C(char *);
extern void func_021EBC58(u8 *,int,int,int);
extern void func_021EE038(char *,int,int,int);
int func_021E5DD8(u8 *p){func_021EBA5C(*(char * *)&((struct Obj00000 *)p)->f2C,24);func_021DD14C((char *)p);func_021EBC58(p,0,3,26);func_021EE038((char *)p,0,1,1);return 53;}
