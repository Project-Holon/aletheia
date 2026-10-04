/*
 * function: func_021B9DAC
 * address: 0x021B9DAC
 * packet: pkt_ov221_021B9DAC
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * shape: explicit enum return local holds FALSE then conditionally TRUE after the int flag test.
 * symbols:
 *   func_02040804 0x02040804 arm
 */
#include "../include/Obj26069.h"
#include "../include/Obj26070.h"
extern unsigned func_02040804(unsigned);
typedef enum Bool { BOOL_FALSE=0,BOOL_TRUE=1 } Bool;
Bool func_021B9DAC(char *p){int flag;Bool result;if(((struct Obj26070 *)(*(char * *)&((struct Obj26069 *)p)->f4))->f4)return BOOL_TRUE;flag=1;if(func_02040804(1))flag=0;result=BOOL_FALSE;if(flag)result=BOOL_TRUE;return result;}
