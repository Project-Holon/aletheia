/*
 * function: func_021BC9E4
 * address:  0x021BC9E4
 * packet:   pkt_ov016_021BC9E4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_BTNlInit (libdwcutil.TWL.HYB.a button.o)
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5394  0x021D5394  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   func_021BCBB4  0x021BCBB4  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021BCC44  0x021BCC44  arm  ov016
 *   g_021DA008  0x021DA008  data
 *   g_021DE508  0x021DE508  data
 *   g_021DA018  0x021DA018  data
 */

typedef struct {
    void *cell[2];
    void *cell8;
    void *task;
    unsigned char pad[6];
    signed char s16;
    unsigned char kind;
    unsigned char pad2[4];
} MemBtnT;

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5394(int lcd, int idx, int head);
extern void func_021D51F0(void *cell, int idx, int priority);
extern void func_021BCBB4(int y);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021BCC44(void *task);
extern unsigned char g_021DA008[7];
extern MemBtnT *g_021DE508;
extern unsigned char g_021DA018[7][2];

void func_021BC9E4(int kind)
{
    int btnNum;
    int i;

    btnNum = g_021DA008[kind];
    g_021DE508 = func_021D6414(0x1c, 4);
    g_021DE508->s16 = -2;
    g_021DE508->kind = kind;
    for (i = 0; i < btnNum; i++) {
        g_021DE508->cell[i] = func_021D5394(0, g_021DA018[kind][i], 1);
        func_021D51F0(g_021DE508->cell[i], -1, 1);
    }
    g_021DE508->cell8 = func_021D5394(0, 1, 1);
    func_021D51F0(g_021DE508->cell8, -1, 1);
    func_021BCBB4(0xc0);
    g_021DE508->task = func_021D7680(0, (void (*)(void *, void *))func_021BCC44, 0, 0x78);
}
