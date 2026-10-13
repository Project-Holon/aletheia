/*
 * function: VCT_AUDIO_GetPendingHead
 * address:  0x021B1488
 * packet:   pkt_ov013_021B1488
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VCT_AUDIO_GetPendingHead (libos.TWL.HYB.a(os_thread.o))
 *
 * symbols:
 *   OSi_IsThreadInitialized  0x021B4B98  data
 */

extern int OSi_IsThreadInitialized;

int VCT_AUDIO_GetPendingHead(void)
{
    return OSi_IsThreadInitialized;
}
