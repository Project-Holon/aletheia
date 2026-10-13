/*
 * function: func_021CE844
 * address:  0x021CE844
 * packet:   pkt_ov016_021CE844
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskSetPltt (libdwcutil.TWL.HYB.a screen.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE844.c \n *       --func func_021CE844 --addr 0x021CE844 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   gScreenWork     0x021DE630  data
 */

typedef struct { void *task; unsigned char buf[0x600]; unsigned char dirty; } MemScr;
/* screen.o .bss: MemScr, then Pltt (src, dst), addressed section-relative from one symbol */
typedef struct { MemScr *scr; void *src; void *dst; } ScreenBss;
extern ScreenBss gScreenWork;
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void DWCi_TSKlDelete(int kind, void *task);

void func_021CE844(void *task)
{
    MIi_CpuCopy16(gScreenWork.src, (void *)0x05000000, 0x200);
    DWCi_TSKlDelete(1, task);
}
