/*
 * function: func_021BE8F4
 * address: 0x021BE8F4
 * packet: pkt_ov203_021BE8F4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj10863.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;

void * func_021BE8F4(char *p,u8 *q) { int x=0;switch(((struct Obj10863 *)p)->f6){case 1:x=q[10];break;case 2:x=q[8];break;case 3:x=q[13];break;}if(x>=((struct Obj10863 *)p)->f4)x=0;return (void *)(((struct Obj10863 *)p)->f0+x*8); }
