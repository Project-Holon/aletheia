/*
 * function: MUSICAL_MCSS_DeleteRenderObj
 * address: 0x021F51B0
 * packet: pkt_ov112_021F51B0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_FreeRenderObj 0x021F5330 thumb ov112
 *   MUSICAL_MCSS_FreeRenderPool 0x021F5644 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10302.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_FreeRenderObj(int,int);
extern void MUSICAL_MCSS_FreeRenderPool(char *p);
extern u32 func_020307B0(void *p);
typedef struct { int f0, f4, active; } Fields;
void MUSICAL_MCSS_DeleteRenderObj(int a) { int i; for(i=0;i<8;i++) { if(((Fields *)(a+i*556))->active==1)MUSICAL_MCSS_FreeRenderObj(a,a+8+i*556); } MUSICAL_MCSS_FreeRenderPool(((struct Obj10302 *)a)->f4); func_020307B0((void *)a); }
