/*
 * function: initObj
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
 *        C_CELL[6]` instead of plain makes the load read through a const
 *        table and the front end hoists the scaled index above the store.
 *        Nothing else in the body moves: `j = i + 3` stays.
 *
 * sdk:      initObj (libdwcutil.TWL.HYB.a scenesetselectap.o)
 *
 * symbols:
 *   DWCi_SETTINGlGetSetType  0x021CF7F4 arm   ov016
 *   DWCi_CEINlSetExCell  0x021D5394 arm   ov016
 *   DWCi_CELLlSetPosition  0x021D5118 arm   ov016
 *   DWCi_CELLlSetPriority  0x021D51F0 arm   ov016
 *   C_CELL    0x021DA72C data
 *   sSceneSetSelectApCellTypes    0x021DA720 data
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

extern unsigned char DWCi_SETTINGlGetSetType(unsigned int i);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern const struct tagCOORD C_CELL[6];
extern unsigned char sSceneSetSelectApCellTypes[4];
extern struct SCENESETSELECTAP_BSS g_021DE60C;

void initObj(void)
{
    int j;
    int type;
    int i;

    for (i = 0; i < 3; i++) {
        type = DWCi_SETTINGlGetSetType(i);
        if (type == 0xff) {
            type = 3;
        } else {
            j = i + 3;
            g_021DE60C.MemSssa->cell[i + 3] = DWCi_CEINlSetExCell(0, 0x11, 1);
            DWCi_CELLlSetPosition(g_021DE60C.MemSssa->cell[i + 3], -1, C_CELL[j].x, C_CELL[j].y);
            DWCi_CELLlSetPriority(g_021DE60C.MemSssa->cell[i + 3], -1, 3);
        }
        g_021DE60C.MemSssa->cell[i] = DWCi_CEINlSetExCell(0, sSceneSetSelectApCellTypes[type], 1);
        DWCi_CELLlSetPosition(g_021DE60C.MemSssa->cell[i], -1, C_CELL[i].x, C_CELL[i].y);
        DWCi_CELLlSetPriority(g_021DE60C.MemSssa->cell[i], -1, 3);
    }
}
