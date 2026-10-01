/*
 * function: func_021BA990
 * address:  0x021BA990
 * packet:   pkt_ov088_021BA990
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020419E4  0x020419E4  arm
 *   func_0204A648  0x0204A648  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 */

typedef unsigned long u32;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern void func_020419E4(void);
extern void func_0204A648(void);

void func_021BA990(void)
{
    func_020419E4();
    func_0204A648();
    OSi_IRQ_CHECK_FLAG |= 1;
}
