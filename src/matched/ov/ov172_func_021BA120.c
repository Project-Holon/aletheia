/*
 * unit: yes
 * function: CTVT_MIC_StopCapture, CTVT_MIC_IsCapturing, CTVT_MIC_GetReadyBytes, CTVT_MIC_GetBuffer
 * address: 0x021BA120
 * packet: pkt_ov172_021BA120
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MIC_StopLimitedSampling 0x0208B528 arm
 *   MIC_GetLastSamplingAddress 0x0208B4B8 arm
 */
typedef unsigned int u32;
extern int MIC_StopLimitedSampling(void);
extern void *MIC_GetLastSamplingAddress(void);
int CTVT_MIC_StopCapture(u32 *p)
{
    if (p[2] == 0) return 1;
    if (MIC_StopLimitedSampling() == 0) {
        p[0] = (u32)MIC_GetLastSamplingAddress() - p[1] + 4;
        if (p[0] > 51200) p[0] = 51200;
        p[2] = 0;
        return 1;
    }
    return 0;
}
u32 CTVT_MIC_IsCapturing(u32 *p) { return p[2]; }
u32 CTVT_MIC_GetReadyBytes(u32 *p)
{
    if (p[0] > 2048) return p[0] - 2048;
    return 0;
}
u32 CTVT_MIC_GetBuffer(u32 *p) { return p[1]; }
