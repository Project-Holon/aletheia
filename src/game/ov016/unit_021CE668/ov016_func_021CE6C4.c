/*
 * function: func_021CE6C4
 * address:  0x021CE6C4
 * packet:   pkt_ov016_021CE6C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SCREENlEnd (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE6C4.c \n *       --func func_021CE6C4 --addr 0x021CE6C4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE630     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss g_021DE630;
extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D6438(void **mem);

void func_021CE6C4(void)
{
    func_021D7744(1, g_021DE630.scr->task);
    func_021D6438((void **)0x021DE630);
}
