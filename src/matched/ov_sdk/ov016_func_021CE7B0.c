/*
 * function: DWCi_SCREENlCopyPalette
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE7B0.c \n *       --func DWCi_SCREENlCopyPalette --addr 0x021CE7B0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gScreenWork     0x021DE630  data
 *   func_021CE7EC  0x021CE7EC  arm  ov016
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss gScreenWork;
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CE7EC(void *task);

void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor)
{
    gScreenWork.src = (unsigned char *)src + sColor * 32;
    gScreenWork.dst = (unsigned char *)0x05000000 + dColor * 32;
    DWCi_TSKlForm(1, func_021CE7EC, 0, 0x78);
}
