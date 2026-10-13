/*
 * function: VCT_AUDIO_PeekReadyPacket
 * address: 0x021B190C
 * packet: pkt_ov013_021B190C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctReadyHead 0x021B4BAC data a4
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */
typedef unsigned int u32;
extern void *gVctReadyHead[];
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
void *VCT_AUDIO_PeekReadyPacket(unsigned int i)
{
    u32 h = OS_DisableInterrupts();
    if (gVctReadyHead[i] != 0) {
        OS_RestoreInterrupts(h);
        return gVctReadyHead[i];
    }
    OS_RestoreInterrupts(h);
    return 0;
}
