/*
 * file:     mi_init.c
 * function: func_0208361C
 * address:  0x0208361C
 * packet:   pkt_0208361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_Init (libmi.TWL.HYB.a mi_init.o)
 *
 * symbols:
 *   MI_SetWramBank                 0x020821B0  arm
 *   OS_IsRunOnTwl                  0x02085D3C  arm
 *   MI_InitNDma                    0x0272FB10  arm
 *   MI_StopDma                     0x020825F0  arm
 */

void MI_SetWramBank(int cnt);
int OS_IsRunOnTwl(void);
void MI_InitNDma(void);
void MI_StopDma(unsigned long dmaNo);

void func_0208361C(void)
{
    MI_SetWramBank(3);
    if (OS_IsRunOnTwl()) {
        MI_InitNDma();
    }
    MI_StopDma(0);
}
