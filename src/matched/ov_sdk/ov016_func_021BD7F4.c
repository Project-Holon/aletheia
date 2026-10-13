/*
 * function: func_021BD7F4
 * address:  0x021BD7F4
 * packet:   pkt_ov016_021BD7F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ICONlEnd (libdwcutil.TWL.HYB.a(icon.o))
 *
 * symbols:
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE558  0x021DE558  data
 *   g_021DE558_b  0x021DE558  data
 */

#include "../include/G_MemIcon.h"

typedef struct MemIcon MemIcon;

extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void func_021D6F38(unsigned int *obj);
extern void func_021D6438(void **mem);
extern struct MemIcon *g_021DE558;
extern struct MemIcon *g_021DE558_b;

void func_021BD7F4(void)
{
    if (g_021DE558 == 0)
        return;
    DWCi_TSKlDeleteByIndex(0, g_021DE558->task);
    func_021D6F38(g_021DE558->obj);
    func_021D6438((void **)(&g_021DE558_b));
}
