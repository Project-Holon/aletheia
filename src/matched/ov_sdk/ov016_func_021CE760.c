/*
 * function: taskLoad
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE760.c \n *       --func taskLoad --addr 0x021CE760 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   gScreenWork     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss gScreenWork;
extern void DC_FlushRange(void *startAddr, unsigned long nBytes);
extern void GX_LoadBG2Scr(void *pSrc, unsigned long offset, unsigned long szByte);

void taskLoad(void)
{
    if (!gScreenWork.scr->dirty)
        return;
    DC_FlushRange(gScreenWork.scr->buf, 0x600);
    GX_LoadBG2Scr(gScreenWork.scr->buf, 0, 0x600);
    gScreenWork.scr->dirty = 0;
}
