/*
 * function: func_021BCCB0
 * address:  0x021BCCB0
 * packet:   pkt_ov016_021BCCB0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskStart1 (libdwcutil.TWL.HYB.a(button.o))
 *
 * symbols:
 *   func_021D771C  0x021d771c  arm  ov016
 *   g_021DE508  0x021de508  data
 *   func_021BCD00  0x021bcd00  arm  ov016
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

extern void func_021D771C();
extern void func_021BCD00(void);

void func_021BCCB0(void *task)
{
    g_021DE508->input = -1;
    g_021DE508->count++;
    if (g_021DE508->count >= 4) {
        g_021DE508->count = 0;
        func_021D771C(task, func_021BCD00);
    }
}
