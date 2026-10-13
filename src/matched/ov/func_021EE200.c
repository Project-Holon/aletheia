/*
 * function: func_021EE200
 * address:  0x021EE200
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_DeleteSys  0x02025588  thumb  arm9
 *   BMP_OAM_Delete  0x0202570C  thumb  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *
 * Walk 9 8-byte records releasing both words of each, then the
 *   head.
 */
#include "../include/Obj18525.h"


struct Grid;
struct Obj020437AC;
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
extern void BMP_OAM_DeleteSys(void *p);
void func_021EE200(char *p)
{
    unsigned i;
    for (i = 0; i < 9; i++) {
        BMP_OAM_Delete((struct Grid *)(*(int *)(p + i * 8 + 4)));
        BMP_Delete((struct Obj020437AC *)(*(int *)(p + i * 8 + 8)));
    }
    BMP_OAM_DeleteSys((void *)(((struct Obj18525 *)p)->f0));
}
