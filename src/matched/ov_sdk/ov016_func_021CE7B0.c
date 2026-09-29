/*
 * function: func_021CE7B0
 * address:  0x021CE7B0
 * packet:   pkt_ov016_021CE7B0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SCREENlCopyPalette (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE7B0.c \n *       --func func_021CE7B0 --addr 0x021CE7B0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE630     0x021DE630  data
 *   func_021CE7EC  0x021CE7EC  arm  ov016
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss g_021DE630;
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CE7EC(void *task);

void func_021CE7B0(void *src, int sColor, int dColor)
{
    g_021DE630.src = (unsigned char *)src + sColor * 32;
    g_021DE630.dst = (unsigned char *)0x05000000 + dColor * 32;
    func_021D7680(1, func_021CE7EC, 0, 0x78);
}
