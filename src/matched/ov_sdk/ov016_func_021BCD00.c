/*
 * function: func_021BCD00
 * address:  0x021BCD00
 * packet:   pkt_ov016_021BCD00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskMain (libdwcutil.TWL.HYB.a button.o)
 *
 * symbols:
 *   func_021D600C  0x021D600C  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 *   func_021D4FE0  0x021D4FE0  arm  ov016
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   func_021D5118  0x021D5118  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021BCF5C  0x021BCF5C  arm  ov016
 *   g_021DE508  0x021DE508  data
 *   g_021DA008  0x021DA008  data
 *   g_021DA010  0x021DA010  data
 *   g_021DA026  0x021DA026  data
 *   g_021DA004  0x021DA004  data
 *   g_021DA018  0x021DA018  data
 */

typedef struct { unsigned short l, t, r, b; } Rect;
typedef struct { unsigned short x, y; } Coord;
typedef struct {
    void *cellButton[2];
    void *cellBack;
    void *task;
    void *release;
    unsigned short count;
    signed char input;
    unsigned char kind;
    unsigned char disable;
    unsigned char end;
} MemBtnT;

typedef unsigned short u16;
struct tagCOORD;
struct tagRECT;
extern void func_021D600C(const struct tagCOORD *coord, const struct tagCOORD *size, struct tagRECT *rect);
extern int func_021D696C(u16 *a);
extern char *func_021D4FE0(char *p, unsigned int i);
extern void func_021D52D4(int lcd, int idx, void *obj);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int priority);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021BCF5C(void *task);
extern MemBtnT *g_021DE508;
extern unsigned char g_021DA008[7];
extern Coord g_021DA010[2];
extern unsigned char g_021DA026[7][2];
extern Coord g_021DA004;
extern unsigned char g_021DA018[7][2];

void func_021BCD00(void)
{
    Rect r;
    int btnNum;
    int i;

    btnNum = g_021DA008[g_021DE508->kind];
    if (!g_021DE508->disable) {
        if (g_021DE508->input != -1)
            return;
        for (i = 0; i < btnNum; i++) {
            func_021D600C((const struct tagCOORD *)(&g_021DA010[g_021DA026[g_021DE508->kind][i]]), (const struct tagCOORD *)(&g_021DA004), (struct tagRECT *)(&r));
            if (func_021D696C((u16 *)(&r))) {
                if (g_021DE508->release)
                    break;
                {
                    int cellIdx = g_021DA018[g_021DE508->kind][i];
                    func_021D52D4(0, cellIdx + 1, func_021D4FE0(g_021DE508->cellButton[i], 0));
                }
                func_021D5118(g_021DE508->cellButton[i], -1,
                              g_021DA010[g_021DA026[g_021DE508->kind][i]].x,
                              g_021DA010[g_021DA026[g_021DE508->kind][i]].y);
                func_021D51F0(g_021DE508->cellButton[i], -1, 1);
                g_021DE508->release = func_021D7680(0, (void (*)(void *, void *))func_021BCF5C, 0, 0x6e);
                g_021DE508->input = i;
                return;
            }
        }
    }
    g_021DE508->input = -1;
}
