/*
 * function: func_021DF7E8
 * address: 0x021DF7E8
 * packet: pkt_ov137_021DF7E8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 */
#include "../include/Obj23766.h"
struct S02021D50;extern void PALANM_TransferPalettes(struct S02021D50 *);extern void CLACT_VBlankSystem(void);extern void func_020419E4(void);
void func_021DF7E8(void *arg,char *p){PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj23766 *)p)->fD78);CLACT_VBlankSystem();func_020419E4();}
