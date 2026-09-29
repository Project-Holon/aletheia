/*
 * function: func_021D17FC
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
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D1B3C  0x021D1B3C  arm  ov016
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

extern void func_021D7724();
extern void *func_021D7680();
extern void func_021D1B3C(void *task);
extern MemWinT *g_021DE658;

void func_021D17FC(void *task)
{
    g_021DE658->input = -1;
    g_021DE658->countWait++;
    if (g_021DE658->countWait < 0x78)
        return;
    func_021D7724(0, task);
    g_021DE658->task = func_021D7680(1, func_021D1B3C, 0, 0x78);
}
