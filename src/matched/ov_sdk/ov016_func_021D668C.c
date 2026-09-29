/*
 * function: func_021D668C
 * address:  0x021D668C
 * packet:   pkt_ov016_021D668C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      readTouch (libdwcutil.TWL.HYB.a(input.o))
 *
 * symbols:
 *   func_0208AF08  0x0208AF08  arm
 *   func_0208B104  0x0208B104  arm
 *   func_021D5FE8  0x021D5FE8  arm  ov016
 *   func_0207C994  0x0207C994  arm
 *   g_021DE688     0x021DE688  data
 *
 * input.o's statics sit in one block; the vendor reaches them through one
 * pool word anchored at 0x021DE688 (DWCi_IPTlCheckFold's local static fold),
 * so the block is a struct overlay named by offset.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef long           s32;
typedef _Bool bool;

typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

typedef struct tagCOORD {
    u16 x;
    u16 y;
} COORD;

typedef struct {
    TPData tp[5];
    COORD coord;
    COORD last;
    u8 pad30[8];
    u8 touch : 1;
    u8 trig : 1;
    u8 repeat : 1;
    u8 release : 1;
} InputWork;

typedef struct {
    u8 fold;
    u8 cnt;
    u8 pad2[2];
    InputWork *work;
} InputStatics;

extern u16 func_0208AF08(void);
extern void func_0208B104(TPData *disp, TPData *raw);
extern void func_021D5FE8(s32 x, s32 y, COORD *coord);
extern s32 func_0207C994(s32 a, s32 b);
extern InputStatics g_021DE688;

void func_021D668C(void)
{
    TPData p;
    int idx;
    int lastIdx;
    int i;
    bool last;
    bool touch;

    last = g_021DE688.work->touch;
    touch = 0;
    idx = func_0208AF08();
    g_021DE688.work->last = g_021DE688.work->coord;
    for (i = 0; i < 4; i++, idx = func_0207C994(idx + 4, 5)) {
        if (g_021DE688.work->tp[idx].touch == 1 && g_021DE688.work->tp[idx].validity == 0) {
            touch = 1;
            func_0208B104(&p, &g_021DE688.work->tp[idx]);
            func_021D5FE8(p.x, p.y, &g_021DE688.work->coord);
            break;
        }
    }
    g_021DE688.work->trig = touch & (touch ^ last);
    g_021DE688.work->release = last & (touch ^ last);
    g_021DE688.work->touch = touch;
    g_021DE688.work->repeat = g_021DE688.work->trig;
    if (!touch) {
        g_021DE688.cnt = 0;
        return;
    }
    if (++g_021DE688.cnt == 40) {
        g_021DE688.work->repeat = 1;
        return;
    }
    if (g_021DE688.cnt == 47) {
        g_021DE688.work->repeat = 1;
        g_021DE688.cnt = 40;
    }
}
