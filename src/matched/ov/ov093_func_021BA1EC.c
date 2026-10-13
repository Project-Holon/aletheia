/*
 * function: func_021BA1EC
 * address: 0x021BA1EC
 * packet: pkt_ov093_021BA1EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum Boolean local keeps zero live across the call and one shared exit;
 * int folds to two returns (27 concrete bytes differ).
 * symbols:
 *   BTL_MAIN_IsCommCompetitor 0x021B6818 thumb ov093
 */
#include "../include/Obj21004.h"
typedef unsigned char u8;
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern unsigned int BTL_MAIN_IsCommCompetitor(unsigned int *p);
BOOL func_021BA1EC(char **p)
{
    BOOL result = FALSE;
    if (BTL_MAIN_IsCommCompetitor((unsigned int *)((int *)*p)) == 1) {
        if (((struct Obj21004 *)(*p))->f7F) result = TRUE;
    }
    return result;
}
