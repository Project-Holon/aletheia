/*
 * function: func_021BD5A8
 * address:  0x021BD5A8
 * packet:   pkt_ov016_021BD5A8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FOCUSlDelete (libdwcutil.TWL.HYB.a(focus.o))
 *
 * symbols:
 *   DWCi_CELLlDelete                 0x021D4F60  arm  ov016
 *   g_021DE550                       0x021DE550  data
 */

#include "../include/G_MemFocus.h"

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    void *cell[4];
} MemFocus;

extern struct MemFocus *g_021DE550;
extern void DWCi_CELLlDelete(void *cell);

void func_021BD5A8(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (g_021DE550->cell[i]) {
            DWCi_CELLlDelete(g_021DE550->cell[i]);
            g_021DE550->cell[i] = 0;
        }
    }
}
