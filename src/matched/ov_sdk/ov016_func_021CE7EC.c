/*
 * function: func_021CE7EC
 * address:  0x021CE7EC
 * packet:   pkt_ov016_021CE7EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskCopyPltt (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE7EC.c \n *       --func func_021CE7EC --addr 0x021CE7EC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_02082A60  0x02082A60  arm
 *   func_021D7724  0x021D7724  arm  ov016
 *   g_021DE630     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss g_021DE630;
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_021D7724(int kind, void *task);

void func_021CE7EC(void *task)
{
    func_02082A60(g_021DE630.src, g_021DE630.dst, 0x20);
    func_021D7724(1, task);
}
