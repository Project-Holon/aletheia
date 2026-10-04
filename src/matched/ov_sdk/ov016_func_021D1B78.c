/*
 * function: func_021D1B78
 * address:  0x021D1B78
 * packet:   pkt_ov016_021D1B78
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd1 (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D1868  0x021D1868  arm  ov016
 *   func_021D771C  0x021D771C  arm  ov016
 *   func_021D1C04  0x021D1C04  arm  ov016
 *   func_021D1C5C  0x021D1C5C  arm  ov016
 *   g_021DE658     0x021DE658  data
 */

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

extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021D1868(int y);
extern void func_021D771C(char *p, unsigned int v);
extern void func_021D1C04(void *task);
extern void func_021D1C5C(void *task);
extern MemWinT *g_021DE658;

void func_021D1B78(void *task)
{
    int x;
    int y;

    func_021D5250(g_021DE658->cellWin, 0, &x, &y);
    y += 12;
    func_021D1868(y);
    if (y < 192)
        return;
    if (g_021DE658->dark != 0)
        func_021D771C(task, (unsigned int)func_021D1C04);
    else
        func_021D771C(task, (unsigned int)func_021D1C5C);
}
