/*
 * function: func_0208361C
 * address:  0x0208361C
 * packet:   pkt_0208361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   MI_SetWramBank  0x020821B0  arm
 *   OS_IsRunOnTwl   0x0209A1C0  arm
 *   MI_InitNDma     0x0208358C  arm
 *   MI_StopDma      0x020825F0  arm
 */

typedef unsigned long u32;

extern void MI_SetWramBank(u32 bank);
extern int OS_IsRunOnTwl(void);
extern void MI_InitNDma(void);
extern void MI_StopDma(u32 dmaNo);

void func_0208361C(void)
{
    MI_SetWramBank(3);
    if (OS_IsRunOnTwl())
        MI_InitNDma();
    MI_StopDma(0);
}
