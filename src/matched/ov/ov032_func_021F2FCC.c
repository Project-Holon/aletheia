/*
 * function: BEACON_VIEW_DeleteActors
 * address:  0x021F2FCC
 * packet:   pkt_ov032_021F2FCC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_DeleteActors 0x021F2FCC thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BEACON_VIEW_DeleteEntry 0x021F34C8 thumb ov032
 *   BEACON_VIEW_DeletePanelActors 0x021F32D4 thumb ov032
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj00812.h"

extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern void BEACON_VIEW_DeleteEntry(char *, int);
extern void BEACON_VIEW_DeletePanelActors(char *);
struct Bank;
extern void BMP_OAM_DeleteSys(void *p);
extern void CLACT_DeleteRenderer(int);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void BEACON_VIEW_DeleteActors(char *p)
{
    int i;

    BG_SYS_SetSubPlaneVisible(0x10, 0);
    for (i = 0; i < 5; i++) {
        BEACON_VIEW_DeleteEntry(p, (unsigned char)i);
    }
    BEACON_VIEW_DeletePanelActors(p);
    BMP_OAM_DeleteSys((void *)(((struct Obj00812 *)p)->f124));
    CLACT_DeleteRenderer(((struct Obj00812 *)p)->f12C);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj00812 *)p)->f128));
}
