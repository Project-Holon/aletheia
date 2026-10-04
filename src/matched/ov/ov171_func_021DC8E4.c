/*
 * function: func_021DC8E4
 * address: 0x021DC8E4
 * packet: pkt_ov171_021DC8E4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum address base preserves split pools; halfword offset closes r1/r2 allocation; const input retains reads.
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 *   d_02FE0000 0x02FE0000 data a4
 */
#include "../include/Obj24049.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S02021D50;
extern void func_020419E4(void),func_0204A648(void);
extern void func_02021D50(struct S02021D50*);
extern u8 d_02FE0000[];
void func_021DC8E4(void*unused,const u8*p){enum Offset{check=0x3ff8};u16 off;enum Base{start=0x02fe0000};enum Base base;func_020419E4();func_0204A648();func_02021D50(*(struct S02021D50*const *)&((struct Obj24049 *)p)->fB30);base=start;off=check;*(u32*)((u32)base+off)|=1;}
