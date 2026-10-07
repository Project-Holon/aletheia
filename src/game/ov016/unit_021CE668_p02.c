/*
 * file:     unit_021CE668_p02.c
 * unit:     yes
 * function: func_021CE760, func_021CE7B0, func_021CE7EC, func_021CE818, func_021CE844
 * address:  0x021CE760
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020862F0  0x020862F0  arm
 *   func_0207EB78  0x0207EB78  arm
 *   g_021DE630     0x021DE630  data
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_02082A60  0x02082A60  arm
 *   func_021D7724  0x021D7724  arm  ov016
 */
typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;

/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;

extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_0207EB78(void *pSrc, unsigned long offset, unsigned long szByte);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_021D7724(int kind, void *task);
void func_021CE760(void);
void func_021CE7B0(void *src, int sColor, int dColor);
void func_021CE7EC(void *task);
void func_021CE818(unsigned int v);
void func_021CE844(void *task);
extern ScreenBss g_021DE630;


void func_021CE760(void)
{
    if (!g_021DE630.scr->dirty)
        return;
    func_020862F0(g_021DE630.scr->buf, 0x600);
    func_0207EB78(g_021DE630.scr->buf, 0, 0x600);
    g_021DE630.scr->dirty = 0;
}


/*
 * sdk:      DWCi_SCREENlCopyPalette (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE7B0.c \n *       --func func_021CE7B0 --addr 0x021CE7B0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CE7B0(void *src, int sColor, int dColor)
{
    g_021DE630.src = (unsigned char *)src + sColor * 32;
    g_021DE630.dst = (unsigned char *)0x05000000 + dColor * 32;
    func_021D7680(1, func_021CE7EC, 0, 0x78);
}


/*
 * sdk:      taskCopyPltt (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE7EC.c \n *       --func func_021CE7EC --addr 0x021CE7EC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CE7EC(void *task)
{
    func_02082A60(g_021DE630.src, g_021DE630.dst, 0x20);
    func_021D7724(1, task);
}


/*
 * Record v and hand the companion entry point to the timer helper.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE818.c \
 *       --func func_021CE818 --addr 0x021CE818 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CE818(unsigned int v)
{
    char *g = (char *)0x021DE630;
    *(unsigned int *)(g + 4) = v;
    func_021D7680(1, func_021CE844, 0, 0x78);
}


/*
 * sdk:      taskSetPltt (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE844.c \n *       --func func_021CE844 --addr 0x021CE844 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CE844(void *task)
{
    func_02082A60(g_021DE630.src, (void *)0x05000000, 0x200);
    func_021D7724(1, task);
}
