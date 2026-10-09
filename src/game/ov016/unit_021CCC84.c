/*
 * file:     unit_021CCC84.c
 * function: input
 * address:  0x021CCC84
 * packet:   pkt_ov016_021CCC84
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      input (libdwcutil.TWL.HYB.a scenesetselectwa)
 * symbols:
 *   DWCi_Flag                        0x021C0EF0  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   moveFocus                        0x021CD018  arm   ov016
 *   g_021DA818                       0x021DA818  data
 *   g_021DE614                       0x021DE614  data
 *   g_021DA85C                       0x021DA85C  data
 *   g_021DA858                       0x021DA858  data
 *   g_021DA85A                       0x021DA85A  data
 *   g_021DA85E                       0x021DA85E  data
 */

#include "../../matched/include/G_FocusState.h"
#include "../../matched/include/G_021DA85C.h"
#include "../../matched/include/G_tagRECT4.h"
#include "../../matched/include/G_021DA85E.h"

typedef _Bool bool;
typedef signed char s8;
typedef unsigned short u16;

extern struct tagRECT4 g_021DA818[4][4];
extern struct FocusState g_021DE614;
extern struct tagRECT4 g_021DA858[4][4];
extern struct G_021DA85C g_021DA85C[4][4];
extern struct tagRECT4 g_021DA85A[4][4];
extern struct G_021DA85E g_021DA85E[4][4];

extern bool DWCi_Flag(unsigned long flag);
extern bool DWCi_TPlCheckTrigger(struct tagRECT4 *r);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);

static void moveFocus(int dir);

static void input(void)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        if (DWCi_TPlCheckTrigger(&g_021DA818[DWCi_Flag(1)][i])) {
            DWCi_BTNlSet(1);
            g_021DE614.cur = i;
            DWCi_FOCUSlDisp4(g_021DA858[DWCi_Flag(1)][g_021DE614.cur].v[0],
                             g_021DA85C[DWCi_Flag(1)][g_021DE614.cur].v[0],
                             g_021DA85A[DWCi_Flag(1)][g_021DE614.cur].v[0],
                             g_021DA85E[DWCi_Flag(1)][g_021DE614.cur].v[0]);
            return;
        }
    }
    if (DWCi_IPTlCheckTrigger(1)) {
        DWCi_BTNlSet(1);
        return;
    }
    if (DWCi_IPTlCheckTrigger(2)) {
        DWCi_BTNlSet(0);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x40)) {
        moveFocus(1);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x80)) {
        moveFocus(3);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x20)) {
        moveFocus(0);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x10))
        moveFocus(2);
}
