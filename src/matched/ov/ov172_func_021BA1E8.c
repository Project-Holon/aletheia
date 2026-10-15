/*
 * function: CTVT_MIC_PlayVoice
 * address:  0x021BA1E8
 * packet:   pkt_ov172_021BA1E8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Starts a sample on the channel at +0x20 when n > 0x20; records the handle and span.
 *
 * symbols:
 *   NNS_SndWaveOutStart  0x02072AA0  arm
 *
 * Addresses are Black-image addresses.
 */

extern int NNS_SndWaveOutStart(void *s, int fmt, void *data, int loop,
                         int start, int end, int rate, int vol, int freq, int e);

int CTVT_MIC_PlayVoice(int *self, char *buf, unsigned n, int vol, int freq)
{
    if (n > 0x20) {
        int r = NNS_SndWaveOutStart((void *)self[8], 1, buf + 0x800, 0, 0, (int)(n >> 1), 0x1FF4, vol, freq, 0x40);
        self[3] = r;
        self[5] = 0;
        self[6] = (int)n;
        self[7] = freq;
        return r;
    }
    return 0;
}
