/*
 * function: func_021D7798
 * address: 0x021D7798
 * packet: pkt_ov123_021D7798
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200C5F8 0x0200C5F8 thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D751C 0x021D751C thumb ov123
 */
#include "../include/Obj10445.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MusicalDist;
extern u32 func_0200C5F8(struct MusicalDist *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D751C(int a);
void func_021D7798(u8 *p) { if(func_0200C5F8(((struct Obj10445 *)p)->f30)) { p[174]=0; ((struct Obj10445 *)p)->f30=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x38e); } }
