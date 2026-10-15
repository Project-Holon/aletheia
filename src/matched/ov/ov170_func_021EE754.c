/*
 * function: BOX2_UI_SelectSlot
 * address:  0x021EE754
 * packet:   pkt_ov170_021EE754
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj24038.h"

typedef struct {
    int pad[9];
    int x24;
} Top;

struct WinMgr;
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);

void BOX2_UI_SelectSlot(unsigned char *p, unsigned r)
{
    int a = 0;
    int f = 0;
    if (p[0x18] == 1) {
        a = 2;
        if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3)
            f = 1;
    } else if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3) {
        f = 1;
    } else if (r >= 0x1E) {
        if (BOX2_UI_IsTopBarOpen(*(struct WinMgr * *)&((struct Obj24038 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0 || BOX2_MAIN_GetPartyValueAt((void ***)p, r, p[0x14], 0xA9, a) == 0)
            f = 2;
    } else {
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p[0x14], 0xA9, a) == 0)
            f = 2;
    }
    BOX2_UI_DeleteSlotObjects((char *)p, a, 1, f);
}
