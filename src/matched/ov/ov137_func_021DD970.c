/*
 * function: func_021DD970
 * address: 0x021DD970
 * packet: pkt_ov137_021DD970
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184134 0x02184134 thumb ov022
 */
#include "../include/Obj23716.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(char *p);
extern u16 func_02039338(void);
extern void *func_021DCF50(u8 *p);
extern void func_02184134(u8 *);
int func_021DD970(char *p,int state) {if(func_02039338()==0)func_02184134(func_021DCF50((u8 *)p));((struct Obj23716 *)p)->f118=3;func_021DD924(p);return state;}
