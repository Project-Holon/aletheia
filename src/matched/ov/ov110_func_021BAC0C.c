/*
 * function: func_021BAC0C
 * address: 0x021BAC0C
 * packet: pkt_ov110_021BAC0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCFF0 0x021BCFF0 thumb ov110
 */
#include "../include/Obj13776.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_021BF71C(u8 *);
typedef unsigned int   u32;
extern u32 func_021BCFF0(char *p, u32 index);
int func_021BAC0C(u8 *p) { if((int)func_021BCFF0((char *)(*(u8 * *)&((struct Obj13776 *)p)->f64),(u8)func_021BF71C(*(u8 * *)&((struct Obj13776 *)p)->f18))) return 1; return -1; }
