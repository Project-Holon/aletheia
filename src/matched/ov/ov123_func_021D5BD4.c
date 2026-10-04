/*
 * function: func_021D5BD4
 * address: 0x021D5BD4
 * packet: pkt_ov123_021D5BD4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5928 0x021C5928 arm ov114
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021D5AC0 0x021D5AC0 thumb ov123
 *   func_021D5BA8 0x021D5BA8 thumb ov123
 *   d_021DAA58 0x021DAA58 data a1
 *   d_021DAA60 0x021DAA60 data a1
 */
#include "../include/Obj22944.h"
extern char d_021DAA58[],d_021DAA60[];
extern void func_021D5AC0(void);
extern int func_021D5BA8(char *);
extern int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern void func_02156DE0(int a, int b);
int func_021D5BD4(char *p){((struct Obj22944 *)p)->fB0=0;if(!func_021C5928((void (*)(int,  int,  int))func_021D5AC0,d_021DAA58,d_021DAA60))return 0;func_02156DE0((int)func_021D5BA8,(int)p);return 1;}
