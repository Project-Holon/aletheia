/*
 * function: func_021D4FE4
 * address: 0x021D4FE4
 * packet: pkt_ov122_021D4FE4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02051C88 0x02051C88 arm
 *   func_021D503C 0x021D503C thumb ov122
 *   func_021D4D98 0x021D4D98 thumb ov122
 */
#include "../include/Obj00265.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020221A4(void);extern int func_02051C88(void *);extern void func_021D503C(char *);extern void func_021D4D98(char *);
void func_021D4FE4(char *p) {if(func_020221A4())func_02051C88(((struct Obj00265 *)p)->f40);func_021D503C(p);func_021D4D98(p);}
