/*
 * function: VCT_AUDIO_DecodePendingFrames
 * address:  0x021B111C
 * packet:   pkt_ov013_021B111C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The three sample converters are passed q->fC as a fourth argument: the
 * original keeps the format in r3 across the argument set-up of all three
 * calls, which only a live fourth argument reproduces (a plain local or
 * the bare field lands in r0).
 *
 * symbols:
 *   VCT_AUDIO_GetPendingHead  0x021B1488  arm  ov013
 *   VCT_AUDIO_GetPendingCount  0x021B1498  arm  ov013
 *   VCT_AUDIO_FindPending  0x021B14A8  arm  ov013
 *   VCT_ADPCM_DecodePacket  0x021B043C  arm  ov013
 *   VCT_AUDIO_DecodeMuLaw  0x021B1634  arm  ov013
 *   VCT_AUDIO_ConvertPcm8ToPcm16  0x021B16B4  arm  ov013
 *   VCT_AUDIO_UnlinkPending  0x021B14F8  arm  ov013
 *   VCT_AUDIO_InsertReadyPacket  0x021B1810  arm  ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Voice {
    u32 f0;
    u32 f4;
    u32 f8;
    int fC;
    u8 f10;
    u8 f11;
    u8 pad12[2];
    u32 f14;
    u32 f18;
    u8 buf[0x474 - 0x1c];
    void *f474;
} Voice;

extern Voice *VCT_AUDIO_GetPendingHead(void);
struct AdpcmState;
extern int VCT_AUDIO_GetPendingCount(unsigned int i);
extern Voice *VCT_AUDIO_FindPending(u8 id);
extern void VCT_ADPCM_DecodePacket(struct AdpcmState *hdr, void *dst, int n, int mode);
struct Node;
extern void VCT_AUDIO_DecodeMuLaw(unsigned char *src, short *dst, unsigned int n);
extern void VCT_AUDIO_ConvertPcm8ToPcm16(signed char *src, short *dst, unsigned int n, int fmt);
struct Node;
extern u32 VCT_AUDIO_UnlinkPending(struct Node *n);
extern int VCT_AUDIO_InsertReadyPacket(struct Node *n, u32 idx);
extern void VCT_POOL_FreeFrame(void *p);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);

int VCT_AUDIO_DecodePendingFrames(void)
{
    Voice *v;
    int i;
    int n;
    u8 id;
    int irq;
    Voice *q;
    int fmt;

    v = VCT_AUDIO_GetPendingHead();
    if (v == 0)
        return 0;

    irq = OS_DisableInterrupts();
    id = v->f11;
    n = VCT_AUDIO_GetPendingCount(id);
    for (i = 0; i < n; i++) {
        q = VCT_AUDIO_FindPending(id);
        fmt = q->fC;
        if (fmt >= 2)
            VCT_ADPCM_DecodePacket(q->f474, q->buf, q->f14, fmt);
        else if (fmt == 1)
            VCT_AUDIO_DecodeMuLaw(q->f474, (short int *)q->buf, q->f14);
        else
            VCT_AUDIO_ConvertPcm8ToPcm16(q->f474, (short int *)q->buf, q->f14, fmt);
        q->f474 = q->buf;
        VCT_AUDIO_UnlinkPending((struct Node *)q);
        if (VCT_AUDIO_InsertReadyPacket((struct Node *)q, q->f11) < 0)
            VCT_POOL_FreeFrame(q);
    }
    OS_RestoreInterrupts(irq);
    return n;
}
