/*
 * function: func_021CBDF8
 * address:  0x021CBDF8
 * packet:   pkt_ov016_021CBDF8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes: EXACT at 264 bytes, 10/10 relocations.  The park's 3-line residue
 *        (+0050..+0058: the image computes the C_CELL index `lsl r2, r3, #2`
 *        before the cell store, the parked source after it) closes on the
 *        table's own qualifier: declaring C_CELL `extern const struct tagCOORD
 *        g_021DA72C[6]` instead of plain makes the load read through a const
 *        table and the front end hoists the scaled index above the store.
 *        Nothing else in the body moves: `j = i + 3` stays.
 *
 * sdk:      initObj (libdwcutil.TWL.HYB.a scenesetselectap.o)
 *
 * symbols:
 *   func_021CF7F4  0x021CF7F4 arm   ov016
 *   func_021D5394  0x021D5394 arm   ov016
 *   func_021D5118  0x021D5118 arm   ov016
 *   func_021D51F0  0x021D51F0 arm   ov016
 *   g_021DA72C    0x021DA72C data
 *   g_021DA720    0x021DA720 data
 *   g_021DE60C    0x021DE60C data
 */

#include "../include/G_SCENESETSELECTAP_BSS.h"

struct tagCOORD {
    unsigned short x;
    unsigned short y;
};

struct selobj {
    int f0;
    void *cell[6];
};

extern unsigned char func_021CF7F4(unsigned int i);
extern void *func_021D5394(int lcd, int idx, int head);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int priority);
extern const struct tagCOORD g_021DA72C[6];
extern unsigned char g_021DA720[4];
extern struct SCENESETSELECTAP_BSS g_021DE60C;

void func_021CBDF8(void)
{
    int j;
    int type;
    int i;

    for (i = 0; i < 3; i++) {
        type = func_021CF7F4(i);
        if (type == 0xff) {
            type = 3;
        } else {
            j = i + 3;
            g_021DE60C.MemSssa->cell[i + 3] = func_021D5394(0, 0x11, 1);
            func_021D5118(g_021DE60C.MemSssa->cell[i + 3], -1, g_021DA72C[j].x, g_021DA72C[j].y);
            func_021D51F0(g_021DE60C.MemSssa->cell[i + 3], -1, 3);
        }
        g_021DE60C.MemSssa->cell[i] = func_021D5394(0, g_021DA720[type], 1);
        func_021D5118(g_021DE60C.MemSssa->cell[i], -1, g_021DA72C[i].x, g_021DA72C[i].y);
        func_021D51F0(g_021DE60C.MemSssa->cell[i], -1, 3);
    }
}
