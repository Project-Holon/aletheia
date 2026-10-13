/*
 * function: func_021D1C04
 * address:  0x021D1C04
 * packet:   pkt_ov016_021D1C04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd2 (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   func_0207D6C0  0x0207D6C0  arm
 *   DWCi_TSKlSetParam  0x021D771C  arm  ov016
 *   func_021D1C5C  0x021D1C5C  arm  ov016
 *   g_021DE658     0x021DE658  data
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
extern void func_0207D6C0(u32 addr, int brightness);
extern void DWCi_TSKlSetParam(char *p, unsigned int v);
extern void func_021D1C5C(void *task);
extern struct MemWinT *g_021DE658;

void func_021D1C04(void *task)
{
    g_021DE658->count++;
    func_0207D6C0(0x04000050, g_021DE658->count);
    if (g_021DE658->count < 0)
        return;
    DWCi_TSKlSetParam(task, (unsigned int)func_021D1C5C);
}
