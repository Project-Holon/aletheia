/*
 * function: func_021DD0F4
 * address: 0x021DD0F4
 * packet: pkt_ov183_021DD0F4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 */
#include "../include/Obj00050.h"
#include "../include/Obj24574.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {int x,y;} Pair;
extern void BR_UTIL_StartEffect(char *,u32,const Pair *),BR_UTIL_DeleteTextWin(void *,int);
void func_021DD0F4(char *p, char *a1) { if(((struct Obj00050 *)p)->fE0) { BR_UTIL_StartEffect(*(char * *)&((struct Obj00050 *)p)->fC,0,0); if(((struct Obj00050 *)p)->f18) { BR_UTIL_DeleteTextWin(((struct Obj00050 *)p)->f18,((struct Obj24574 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10); *(int *)&((struct Obj00050 *)p)->f18=0; } ((struct Obj00050 *)p)->fE0=0; } }
