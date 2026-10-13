/*
 * unit: no
 * function: func_021D5E60
 * address: 0x021D5E60
 * packet: pkt_ov123_021D5E60
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_021D6678 0x021D6678 thumb ov123
 *   func_021D6934 0x021D6934 thumb ov123
 */
#include "../include/Obj03267.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void CLACT_DrawSystem(void);
extern void func_021D6678(u8 *);
struct Obj;
extern void func_021D6934(struct Obj *);
void func_021D5E60(u8 *p){(((struct Obj03267 *)p)->f43C6)++;if(((struct Obj03267 *)p)->f43C6>=192)((struct Obj03267 *)p)->f43C6=0;CLACT_DrawSystem();func_021D6678(p);func_021D6934((struct Obj *)p);}
