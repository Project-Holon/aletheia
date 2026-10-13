/*
 * function: VCT_AUDIO_ClearReadyQueue
 * address: 0x021B16E4
 * packet: pkt_ov013_021B16E4
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctReadyTail 0x021B4BC4 data a4
 *   gVctReadyHead 0x021B4BAC data a4
 *   gVctReadyCount 0x021B4BB8 data a4
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */
typedef unsigned int u32;
extern u32 gVctReadyTail[], gVctReadyHead[], gVctReadyCount[];
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
void VCT_AUDIO_ClearReadyQueue(unsigned int i)
{
    u32 h = OS_DisableInterrupts();
    gVctReadyTail[i] = 0;
    gVctReadyHead[i] = 0;
    gVctReadyCount[i] = 0;
    OS_RestoreInterrupts(h);
}
