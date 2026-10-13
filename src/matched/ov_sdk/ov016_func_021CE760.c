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
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   gScreenWork     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss gScreenWork;
extern void DWCi_ScreenDC_FlushRange(void *startAddr, unsigned long nBytes);
extern void GX_LoadBG2Scr(void *pSrc, unsigned long offset, unsigned long szByte);

void func_021CE760(void)
{
    if (!gScreenWork.scr->dirty)
        return;
    DWCi_ScreenDC_FlushRange(gScreenWork.scr->buf, 0x600);
    GX_LoadBG2Scr(gScreenWork.scr->buf, 0, 0x600);
    gScreenWork.scr->dirty = 0;
}
