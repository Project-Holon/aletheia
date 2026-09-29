/*
 * function: func_021BCE7C
 * address:  0x021BCE7C
 * packet:   pkt_ov016_021BCE7C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   func_021D5250  0x021d5250  arm  ov016
 *   func_021BCBB4  0x021bcbb4  arm  ov016
 *   func_021D771C  0x021d771c  arm  ov016
 *   g_021DE508  0x021de508  data
 *   func_021BCEE0  0x021bcee0  arm  ov016
 */

typedef _Bool bool;

typedef struct tagMEMBTN {
    void *cellButton[2];
    void *cellBack;
    void *task;
    void *release;
    unsigned short count;
    signed char input;
    unsigned char kind;
    bool disable;
    bool end;
} MEMBTN;

extern MEMBTN *g_021DE508;

extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021BCBB4(int y);
extern void func_021D771C();
extern void func_021BCEE0(void *task);

void func_021BCE7C(void *task)
{
    int x, y;

    func_021D5250(g_021DE508->cellBack, 0, &x, &y);
    y += 4;
    func_021BCBB4(y);
    if (y >= 192)
        func_021D771C(task, func_021BCEE0);
}
