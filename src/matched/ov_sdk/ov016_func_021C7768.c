/*
 * function: func_021C7768
 * address:  0x021C7768
 * packet:   pkt_ov016_021C7768
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021BF730  0x021BF730  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021C77F4  0x021C77F4  arm  ov016
 *   func_021C7C74  0x021C7C74  arm  ov016
 *   func_021C79B4  0x021C79B4  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern int func_021BF730();
extern void func_021C0E40(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021C77F4();
extern void func_021C7C74();
extern void func_021C79B4();
extern struct MemSsea *g_021DE5E4;

void func_021C7768(void)
{
    int r;

    if (func_021BF730())
        return;
    r = g_021DE5E4->result;
    if (r == 0) {
        func_021C0E40((unsigned int)func_021C77F4);
    } else if (r == 2) {
        func_021D1208(6, 3, 1, -1, 0);
        func_021C0E40((unsigned int)func_021C7C74);
    } else {
        func_021D1208(0x47, 2, 1, -1, 0);
        func_021C0E40((unsigned int)func_021C79B4);
    }
}
