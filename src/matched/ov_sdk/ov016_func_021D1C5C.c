/*
 * function: taskEnd3
 * address:  0x021D1C5C
 * packet:   pkt_ov016_021D1C5C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd3 (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_CELLlDelete  0x021D4F60  arm  ov016
 *   DWCi_FNTlDelete  0x021D5A2C  arm  ov016
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gWindowWork     0x021DE658  data
 *   gMemWindow   0x021DE658  data
 *   sWindowTable2     0x021DA9A6  data
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

extern void DWCi_CELLlDelete(u8 *p);
extern void DWCi_FNTlDelete(char *a);
extern void DWCi_TSKlDelete();
extern void DWCi_HEAPlFree_(void **mem);
extern struct MemWinT *gWindowWork;
extern struct MemWinT *gMemWindow;
extern u8 sWindowTable2[6];

void taskEnd3(void *task)
{
    int i;

    *(volatile unsigned int *)0x04000000 &= ~0xE000;
    DWCi_CELLlDelete(gWindowWork->cellWin);
    DWCi_CELLlDelete(gWindowWork->cellChar);
    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        if (gWindowWork->button[i] != 0)
            DWCi_CELLlDelete(gWindowWork->button[i]);
    }
    DWCi_FNTlDelete(gWindowWork->canv);
    DWCi_TSKlDelete(1, task);
    DWCi_HEAPlFree_((void **)(&gMemWindow));
}
