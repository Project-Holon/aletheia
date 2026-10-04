/*
 * function: func_021BB9C0
 * address: 0x021BB9C0
 * packet: pkt_ov110_021BB9C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype-evidence: BF7FC's legacy source says void; this caller uses r0
 * at 0x021BB9CC/0x021BB9CE, so its observed unsigned result is retained.
 * symbols:
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BBA10 0x021BBA10 thumb ov110
 *   func_021BB9E8 0x021BB9E8 thumb ov110
 */
#include "../include/Obj02460.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 func_021BF7FC(u8 *);
extern void func_021BBA10(u8 *,unsigned);
extern void func_021BB9E8(u8 *,u32);
void func_021BB9C0(u8 *p,int flag) { u32 n=func_021BF7FC(*(u8 * *)&((struct Obj02460 *)p)->f4); if(n>22)n=22; if(flag)func_021BBA10(p,n);else func_021BB9E8(p,n); }
