/*
 * function: func_021D15F0
 * address:  0x021D15F0
 * packet:   pkt_ov016_021D15F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      taskMove (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D1868  0x021D1868  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D17FC  0x021D17FC  arm  ov016
 *   func_021D16B0  0x021D16B0  arm  ov016
 *   g_021DE658     0x021DE658  data
 *   g_021DAA00     0x021DAA00  data
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
extern void *func_021D7680();
extern void func_021D7724();
extern void func_021D17FC(void *task);
extern void func_021D16B0(void *task);
extern MemWinT *g_021DE658;
extern u16 g_021DAA00[][2];

void func_021D15F0(void *task)
{
    int x;
    int y;

    func_021D5250(g_021DE658->cellWin, 0, &x, &y);
    y -= 12;
    if (y > g_021DAA00[g_021DE658->type][0]) {
        func_021D1868(y);
        return;
    }
    func_021D1868(g_021DAA00[g_021DE658->type][0]);
    g_021DE658->task = func_021D7680(0, g_021DE658->type == 5 ? func_021D17FC : func_021D16B0, 0, 0x78);
    func_021D7724(1, task);
}
