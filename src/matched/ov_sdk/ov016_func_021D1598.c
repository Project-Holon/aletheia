/*
 * function: taskV
 * address:  0x021D1598
 * packet:   pkt_ov016_021D1598
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskV (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_WindowG2x_ChangeBlendBrightness_  0x0207D6C0  arm
 *   DWCi_TSKlChangeFunc  0x021D771C  arm  ov016
 *   func_021D15F0  0x021D15F0  arm  ov016
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

typedef unsigned int   u32;
extern void DWCi_WindowG2x_ChangeBlendBrightness_(u32 addr, int brightness);
extern void DWCi_TSKlChangeFunc(char *p, unsigned int v);
extern void func_021D15F0(void *task);
extern struct MemWinT *gWindowWork;

void taskV(void *task)
{
    gWindowWork->count--;
    DWCi_WindowG2x_ChangeBlendBrightness_(0x04000050, gWindowWork->count);
    if (gWindowWork->count > -12)
        return;
    DWCi_TSKlChangeFunc(task, (unsigned int)func_021D15F0);
}
