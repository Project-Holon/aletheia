/*
 * file:     screen.c
 * unit:     yes
 * function: func_021CE668, func_021CE6C4, func_021CE6F0, func_021CE708, func_021CE760, func_021CE7B0, func_021CE7EC, func_021CE818, func_021CE844
 * address:  0x021CE668
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE630  0x021DE630  data
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207EB78  0x0207EB78  arm
 *   func_02082A60  0x02082A60  arm
 *   func_021D7724  0x021D7724  arm  ov016
 */
typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;

/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;

extern void *func_021D6414(unsigned long size, int alignment);
extern void MIi_CpuCopyFast(void *srcp, void *destp, unsigned long size);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void func_021D6438(void **mem);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_0207EB78(void *pSrc, unsigned long offset, unsigned long szByte);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_021D7724(int kind, void *task);
void func_021CE668(void *scr);
void func_021CE6C4(void);
void func_021CE6F0(void);
void func_021CE708(void *src, int pos, int w, int h);
void func_021CE760(void);
void func_021CE7B0(void *src, int sColor, int dColor);
void func_021CE7EC(void *task);
void func_021CE818(unsigned int v);
void func_021CE844(void *task);
extern ScreenBss g_021DE630;




/*
 * sdk:      DWCi_SCREENlInit (libdwcutil.TWL.HYB.a(screen.o))
 */
void func_021CE668(void *scr)
{
	g_021DE630.scr = (MemScr *)func_021D6414(0x608, 4);
	MIi_CpuCopyFast(scr, g_021DE630.scr->buf, 0x600);
	g_021DE630.scr->task = func_021D7680(1, (void (*)(void *))func_021CE760, 0, 0x78);
}




/*
 * sdk:      DWCi_SCREENlEnd (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE6C4.c \n *       --func func_021CE6C4 --addr 0x021CE6C4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
void func_021CE6C4(void)
{
    DWCi_TSKlDeleteByIndex(1, g_021DE630.scr->task);
    func_021D6438((void **)0x021DE630);
}



void func_021CE6F0(void)
{
    g_021DE630.scr->dirty = 1;
}




/*
 * sdk:      DWCi_SCREENlCopy (libdwcutil.TWL.HYB.a(screen.o))
 */
void func_021CE708(void *src, int pos, int w, int h)
{
	unsigned short *sr;
	unsigned short *dst;
	int i;

	sr = (unsigned short *)src;
	dst = (unsigned short *)g_021DE630.scr->buf + pos;
	for (i = 0; i < h; i++) {
		MIi_CpuCopy16(sr, dst, w * 2);
		sr += 32;
		dst += 32;
	}
}



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
