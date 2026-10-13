/*
 * function: func_021C6488
 * address:  0x021C6488
 * packet:   pkt_021C6488
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SNDlPlay   0x021CFFAC   arm
 *   DWCi_TSKlForm   0x021D7680   arm
 *   func_021C61A4   0x021C61A4   arm
 *   gSceneSetApListWork      0x021DE5D8   data
 */

#include "../include/G_SCENESETAPLIST_BSS.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern struct SCENESETAPLIST_BSS gSceneSetApListWork;
extern void DWCi_SNDlPlay(unsigned int v);
extern void *DWCi_TSKlForm(int a, void *b, int c, int d);
extern void  func_021C61A4(void);

void func_021C6488(void)
{
    u8 *p = gSceneSetApListWork.MemSsal;

    if (gSceneSetApListWork.Pos == *(u16 *)(p + 0x40) || p[0x51] <= 4) {
        if (p[0x59] == 0) {
            DWCi_SNDlPlay(9);
            ((u8 *)gSceneSetApListWork.MemSsal)[0x59] = 1;
        }
        return;
    }
    DWCi_SNDlPlay(0x13);
    *(void **)(((u8 *)gSceneSetApListWork.MemSsal) + 0x38) = DWCi_TSKlForm(0, func_021C61A4, 0, 0x78);
}
