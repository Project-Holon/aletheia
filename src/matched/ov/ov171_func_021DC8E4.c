/*
 * function: DENDOU_VIEW_VBlankTask
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
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   d_02FE0000 0x02FE0000 data a4
 */
#include "../include/Obj24049.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S02021D50;
extern void func_020419E4(void),CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct S02021D50*);
extern u8 d_02FE0000[];
void DENDOU_VIEW_VBlankTask(void*unused,const u8*p){enum Offset{check=0x3ff8};u16 off;enum Base{start=0x02fe0000};enum Base base;func_020419E4();CLACT_VBlankSystem();PALANM_TransferPalettes(*(struct S02021D50*const *)&((struct Obj24049 *)p)->fB30);base=start;off=check;*(u32*)((u32)base+off)|=1;}
