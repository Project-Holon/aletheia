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
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   func_021D5AC0 0x021D5AC0 thumb ov123
 *   func_021D5BA8 0x021D5BA8 thumb ov123
 *   d_021DAA58 0x021DAA58 data a1
 *   d_021DAA60 0x021DAA60 data a1
 */
#include "../include/Obj22944.h"
extern char d_021DAA58[],d_021DAA60[];
typedef unsigned int   u32;
extern void func_021D5AC0(void *unused, u32 mode);
extern int func_021D5BA8(char *);
extern int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern void DWC_RAP_SetErrorHookCallback(int a, int b);
int func_021D5BD4(char *p){((struct Obj22944 *)p)->fB0=0;if(!DWC_NdInitAsync((void (*)(int,  int,  int))func_021D5AC0,d_021DAA58,d_021DAA60))return 0;DWC_RAP_SetErrorHookCallback((int)func_021D5BA8,(int)p);return 1;}
