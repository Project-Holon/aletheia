/*
 * function: func_021D16B0
 * address:  0x021D16B0
 * packet:   pkt_ov016_021D16B0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskMain (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   func_021D600C  0x021D600C  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 *   func_021D6824  0x021D6824  arm  ov016
 *   func_021D1A80  0x021D1A80  arm  ov016
 *   g_021DE658  0x021DE658  data
 *   g_021DA9A6  0x021DA9A6  data
 *   g_021DAA2E  0x021DAA2E  data
 *   g_021DA9B4  0x021DA9B4  data
 *   g_021DA9D2  0x021DA9D2  data
 *   g_021DA9BE  0x021DA9BE  data
 *   g_021DA9BF  0x021DA9BF  data
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} CoordT;

typedef struct {
    u16 l, t, r, b;
} RectT;

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

extern void func_021D600C(CoordT *c, CoordT *s, RectT *r);
extern int func_021D696C(RectT *r);
extern int func_021D6824(int key);
extern void func_021D1A80(int idx);
extern MemWinT *g_021DE658;
extern u8 g_021DA9A6[6];
extern CoordT g_021DAA2E[][2];
extern u8 g_021DA9B4[][2];
extern CoordT g_021DA9D2[];
extern signed char g_021DA9BE[][2];
extern signed char g_021DA9BF[][2];

void func_021D16B0(void)
{
    RectT r;
    int i;

    for (i = 0; i < g_021DA9A6[g_021DE658->type]; i++) {
        func_021D600C(&g_021DAA2E[g_021DE658->type][g_021DA9B4[g_021DE658->type][i]],
                      &g_021DA9D2[g_021DE658->type], &r);
        if (func_021D696C(&r)) {
            g_021DE658->input = i;
            break;
        }
    }
    if (func_021D6824(1))
        g_021DE658->input = g_021DA9BE[g_021DE658->type][0];
    if (func_021D6824(2))
        g_021DE658->input = g_021DA9BF[g_021DE658->type][0];
    for (i = 0; i < g_021DA9A6[g_021DE658->type]; i++) {
        if (i == g_021DE658->input) {
            func_021D1A80(i);
            return;
        }
    }
    g_021DE658->input = -1;
}
