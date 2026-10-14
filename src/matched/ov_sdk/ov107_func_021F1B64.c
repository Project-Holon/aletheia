/*
 * function: MB_CommGetChildUser
 * address:  0x021F1B64
 * packet:   pkt_ov107_021F1B64
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_CommGetChildUser (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6FA0  0x021F6FA0  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 */

extern char *g_021F6FA0;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int func_021F2EE8(unsigned short child_aid);

void *MB_CommGetChildUser(unsigned short child_aid)
{
    unsigned long enabled = OS_DisableInterrupts();

    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        MI_CpuCopy8(g_021F6FA0 + 0x1340 + (child_aid - 1) * 22, g_021F6FA0 + 0x1772, 0x16);
        OS_RestoreInterrupts(enabled);
        return g_021F6FA0 + 0x1772;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
