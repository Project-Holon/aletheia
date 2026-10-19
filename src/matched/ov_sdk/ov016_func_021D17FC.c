/*
 * function: taskMain1
 * address:  0x021D17FC
 * packet:   pkt_ov016_021D17FC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskMain1 (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   DWCi_WindowTaskEnd  0x021D1B3C  arm  ov016
 *   gWindowWork     0x021DE658  data
 */

#include "../include/G_MemWinT.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    u16 countWait;
    signed char count;
    signed char input;
    u8 type;
    u8 wait;
    u8 dark;
} MemWinT;

extern void DWCi_TSKlDelete();
extern void *DWCi_TSKlForm();
extern void DWCi_WindowTaskEnd(void *task);
extern struct MemWinT *gWindowWork;

void taskMain1(void *task)
{
    gWindowWork->input = -1;
    gWindowWork->countWait++;
    if (gWindowWork->countWait < 0x78)
        return;
    DWCi_TSKlDelete(0, task);
    gWindowWork->task = DWCi_TSKlForm(1, DWCi_WindowTaskEnd, 0, 0x78);
}
