/*
 * function: func_021D5A58
 * address:  0x021D5A58
 * packet:   pkt_ov016_021D5A58
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes: DIFF, 3 stores reordered (cv->self store vs font store scheduling) plus argument setup order for the 8-arg call at +D0. Everything else identical.
 *
 * sdk:      DWCi_FNTlFormBgEx (libdwcutil.TWL.HYB.a font.o)
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm    ov016
 *   func_02068FC4  0x02068FC4  arm
 *   func_0207DF94  0x0207DF94  arm
 *   func_0207DF60  0x0207DF60  arm
 *   func_02069078  0x02069078  arm
 *   func_021D5F14  0x021D5F14  arm    ov016
 *   func_021D7680  0x021D7680  arm    ov016
 *   func_021D5BC0  0x021D5BC0  arm    ov016
 *   g_021DE680     0x021DE680  data
 *   g_021DAA76     0x021DAA76  data
 *   g_021DAA74     0x021DAA74  data
 *   g_021DAA70     0x021DAA70  data
 */

typedef unsigned short u16;

struct canvas {
    char pad0[0x18];
    struct canvas *self;
    void *font;
    int f20;
    int f24;
    void *buf;
    void *task;
};

extern char *g_021DE680;
extern u16 g_021DAA74[];
extern u16 g_021DAA76[];
extern u16 g_021DAA70[];

extern void *func_021D6414(unsigned long size, int align);
extern void func_02068FC4();
extern void *func_0207DF94(void);
extern void *func_0207DF60(void);
extern void func_02069078();
extern void func_021D5F14(void *c, int col);
extern void *func_021D7680(int kind, void (*f)(void *), void *w, unsigned char prio);
extern void func_021D5BC0(void *t);

void *func_021D5A58(int lcd, int font)
{
    struct canvas *cv;
    void *scr;
    u16 w, h, chr;

    h = g_021DAA76[lcd * 2];
    w = g_021DAA74[lcd * 2];
    cv = (struct canvas *)(g_021DE680 + 0x610) + lcd;
    cv->buf = func_021D6414(w * h * 32, 32);
    if (lcd == 1) {
        *(volatile u16 *)0x04001008 &= 0xFFBF;
        *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xC00;
    } else {
        *(volatile u16 *)0x04000008 &= 0xFFBF;
        *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xC00;
    }
    func_02068FC4(cv, cv->buf, w, h, 4);
    cv->font = g_021DE680 + font * 8;
    cv->self = cv;
    cv->f20 = 1;
    cv->f24 = 1;
    if (lcd == 1)
        scr = func_0207DF94();
    else
        scr = func_0207DF60();
    chr = g_021DAA70[lcd];
    func_02069078(scr, w, h, 0, 0, 0x20, chr, 0xF);
    func_021D5F14(cv, 0);
    cv->task = func_021D7680(1, func_021D5BC0, g_021DE680 + 0x67C + lcd, 0xC8);
    return cv;
}
