/*
 * function: func_021CE760
 * address:  0x021CE760
 * packet:   pkt_ov016_021CE760
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskLoad (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE760.c \n *       --func func_021CE760 --addr 0x021CE760 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_020862F0  0x020862F0  arm
 *   func_0207EB78  0x0207EB78  arm
 *   g_021DE630     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss g_021DE630;
extern void func_020862F0(void *startAddr, unsigned long nBytes);
extern void func_0207EB78(void *pSrc, unsigned long offset, unsigned long szByte);

void func_021CE760(void)
{
    if (!g_021DE630.scr->dirty)
        return;
    func_020862F0(g_021DE630.scr->buf, 0x600);
    func_0207EB78(g_021DE630.scr->buf, 0, 0x600);
    g_021DE630.scr->dirty = 0;
}
