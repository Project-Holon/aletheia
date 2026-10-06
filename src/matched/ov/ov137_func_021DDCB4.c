/*
 * function: func_021DDCB4
 * address: 0x021DDCB4
 * packet: pkt_ov137_021DDCB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 */
#include "../include/Obj14213.h"
#include "../include/Obj23723.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(char *p);
extern u16 func_02039338(void);
extern void *func_021DCF50(u8 *p);
extern int func_021841A4(u8 *);
int func_021DDCB4(char *p,int state) {if(func_02039338()==0)func_021841A4(func_021DCF50((u8 *)p));if(((struct Obj23723 *)(*(char * *)&((struct Obj14213 *)p)->f10))->f20==func_021841A4(func_021DCF50((u8 *)p))) ((struct Obj14213 *)p)->f118=27;return state;}
