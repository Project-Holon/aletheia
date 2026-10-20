/*
 * function: DWCi_SCREENlEnd
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE6C4.c \n *       --func DWCi_SCREENlEnd --addr 0x021CE6C4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_TSKlDeleteEx  0x021D7744  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gScreenWork     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss gScreenWork;
extern void DWCi_TSKlDeleteEx(unsigned int idx, void *r4);
extern void DWCi_HEAPlFree_(void **mem);

void DWCi_SCREENlEnd(void)
{
    DWCi_TSKlDeleteEx(1, gScreenWork.scr->task);
    DWCi_HEAPlFree_((void **)0x021DE630);
}
