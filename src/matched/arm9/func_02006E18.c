/*
 * function: SND_MIC_StoreRecording
 * address:  0x02006E18
 * packet:   pkt_02006E18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SND_MIC_GetBufferAligned  0x02006E2C  thumb
 *   func_02007BD0  0x02007BD0  thumb
 */

typedef unsigned int   u32;
extern u32 SND_MIC_GetBufferAligned(void);
typedef signed char    s8;
struct PerapVoice;
extern void func_02007BD0(struct PerapVoice *p, const s8 *src);

void SND_MIC_StoreRecording(void *a0)
{
    void *res = (void *)SND_MIC_GetBufferAligned();
    func_02007BD0(a0, res);
}
