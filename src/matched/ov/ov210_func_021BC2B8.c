/*
 * function: ZKNSEARCH_SYS_VBlankHandler
 * address: 0x021BC2B8
 * packet: pkt_ov210_021BC2B8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * SDK HW_DTCM integer address arithmetic retains the base symbol and 0x3ff8 offset separately.
 * volatile: 021BC308 reads and 021BC30C writes interrupt-check hardware flag 02FE3FF8.
 * symbols:
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj06692.h"
struct S_02021D50;
extern unsigned d_02FE0000[];
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
void ZKNSEARCH_SYS_VBlankHandler(void *unused,unsigned char *p)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)(*(struct S_02021D50 * *)&((struct Obj06692 *)p)->fC));
    if (p[0x2b8]==1) {
        BG_SYS_SetMainPlaneVisible(10,1);
        BG_SYS_SetSubPlaneVisible(2,1);
        p[0x2b8]=0;
    } else if (p[0x2b8]==2) {
        BG_SYS_SetMainPlaneVisible(10,0);
        BG_SYS_SetSubPlaneVisible(2,0);
        p[0x2b8]=0;
    }
    *(volatile unsigned *)((unsigned)d_02FE0000+0x3ff8) |= 1;
}
