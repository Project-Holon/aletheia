/*
 * function: func_022065C8
 * address: 0x022065C8
 * packet: pkt_ov195_022065C8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02208514 0x02208514 thumb ov195
 *   func_02206A3C 0x02206A3C thumb ov195
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02911.h"
#include "../include/Obj10824.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern void func_02048AC4(void *ptr);
extern void func_02208514(void *,int);
extern void func_02206A3C(char *,int);
extern void func_020307B0(void *);
void func_022065C8(char *p){char *q;u8 i;q=*(char * *)&((struct Obj02911 *)p)->f58;func_02048AC4((void *)(((struct Obj10824 *)q)->f4));if(((struct Obj10824 *)q)->f10)func_02208514(((struct Obj10824 *)q)->f10,((struct Obj02911 *)p)->f0);for(i=0;i<2;i++){if(*(char **)(q+i*4+8))func_02206A3C(*(char **)(q+i*4+8),((struct Obj02911 *)p)->f0);}func_020307B0(q);}
