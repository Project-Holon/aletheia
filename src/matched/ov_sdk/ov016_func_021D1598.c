/*
 * function: func_021D1598
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
 *   func_0207D6C0  0x0207D6C0  arm
 *   func_021D771C  0x021D771C  arm  ov016
 *   func_021D15F0  0x021D15F0  arm  ov016
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

typedef unsigned int   u32;
extern void func_0207D6C0(u32 addr, int brightness);
extern void func_021D771C();
extern void func_021D15F0(void *task);
extern MemWinT *g_021DE658;

void func_021D1598(void *task)
{
    g_021DE658->count--;
    func_0207D6C0(0x04000050, g_021DE658->count);
    if (g_021DE658->count > -12)
        return;
    func_021D771C(task, func_021D15F0);
}
