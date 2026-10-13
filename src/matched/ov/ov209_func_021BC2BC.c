/*
 * function: func_021BC2BC
 * address: 0x021BC2BC
 * packet: pkt_ov209_021BC2BC
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum-typed DTCM base preserves the base-first two-pool address; constant addition folds and enum offset reverses pool/register roles.
 * volatile: hardware interrupt check flag at 02FE3FF8 read and written by 021BC2D4/021BC2D8.
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
#include "../include/Obj25534.h"
#include "../include/Obj25535.h"
struct S02021D50;extern void func_020419E4(void),func_0204A648(void);extern void PALANM_TransferPalettes(struct S02021D50 *);
void func_021BC2BC(void *unused,char *p){enum Base { DTCM_BASE=0x02fe0000 } base;func_020419E4();func_0204A648();PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj25534 *)p)->fC);base=DTCM_BASE;*(volatile unsigned *)&((struct Obj25535 *)base)->f3FF8|=1;}
