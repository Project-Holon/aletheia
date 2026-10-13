/*
 * function: VCT_AUDIO_ReceiveFrame
 * address:  0x021B0F38
 * packet:   pkt_ov013_021B0F38
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The last two arguments are one u64 (an OS tick, stored to v+0x464):
 * split across r3 and the stack, which is what pulls the high word into a
 * register at entry.
 *
 * symbols:
 *   gVctSendState  0x021B3C84  data  ov013  a4
 *   gVctReceiveSources  0x021B3CBC  data  ov013  a4
 *   gVctFrameSpecs  0x021B3AD0  data  ov013  a1
 *   VCT_POOL_AllocFrame  0x021B2FB0  arm  ov013
 *   VCT_AUDIO_FlushReadyQueue  0x021B1720  arm  ov013
 *   VCT_AUDIO_FlushPendingSlot  0x021B133C  arm  ov013
 *   VCT_AUDIO_FlushAllReadyQueues  0x021B1790  arm  ov013
 *   VCT_AUDIO_FlushPendingAll  0x021B1398  arm  ov013
 *   VCT_AUDIO_TrackPacketTiming  0x021B1B94  arm  ov013
 *   VCT_AUDIO_QueuePending  0x021B1404  arm  ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 f0;
    u8 f4;
    u8 f5;
    u16 f6;
    u32 f8;
    u8 data[1];
} Frame;

typedef struct {
    u8 pad0[0x24];
    int f24;
    u8 pad28[0x8];
    u32 f30;
    u32 f34;
    u32 f38;
    u8 pad3C[0x10];
    u32 f4C;
    u8 pad50[0x1c];
    u32 f6C;
    u8 pad70[0x94 - 0x70];
} Chan;

typedef struct {
    u8 a;
    u8 b;
} SizeEnt;

typedef struct {
    u32 f0;
    u32 f4;
    u8 pad8[0x18];
    u32 f20;
} Ctx3C84;

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
    u8 buf[0x45c - 0x1c];
    u32 f45C;
    u32 f460;
    u64 tick;
    u32 f46C;
    u32 f470;
    void *f474;
} Voice;

extern Ctx3C84 gVctSendState;
extern Chan gVctReceiveSources[3];
extern SizeEnt gVctFrameSpecs[];

extern Voice *VCT_POOL_AllocFrame(void);
extern void VCT_AUDIO_FlushReadyQueue(u32 x);
extern void VCT_AUDIO_FlushPendingSlot(u32 x);
extern void VCT_AUDIO_FlushAllReadyQueues(void);
extern void VCT_AUDIO_FlushPendingAll(void);
struct Pkt;
struct Src;
extern int VCT_AUDIO_TrackPacketTiming(struct Src *s, struct Pkt *pkt);
struct Node;
extern int VCT_AUDIO_QueuePending(struct Node *n);
extern void VCT_POOL_FreeFrame(Voice *v);
extern void MI_CpuCopy8(void *src, void *dst, u32 n);

int VCT_AUDIO_ReceiveFrame(u32 id, Frame *hdr, u32 size, u64 tick)
{
    Voice *v;
    Chan *ch;
    int mode;
    u32 i;
    u8 *dst;

    ch = 0;
    if (gVctSendState.f20 == 0)
        return 0;

    for (i = 0; i < 3; i++) {
        if (id == gVctReceiveSources[i].f38) {
            ch = &gVctReceiveSources[i];
            break;
        }
    }
    if (ch == 0)
        return 0;

    if (hdr->f4 == 0x41) {
        ch->f30 = hdr->f6;
        ch->f4C = 0;
        ch->f6C = 1;
        return 0;
    }
    if (hdr->f4 != 0x40)
        return 0;

    mode = hdr->f5 & 0x7f;
    ch->f24 = mode;
    if (mode >= 5)
        return 0;
    if (size != gVctFrameSpecs[mode].a * 0x44 + gVctFrameSpecs[mode].b + 0xc)
        return 0;
    if ((gVctSendState.f4 & (id != 0 ? 1 << id : 1)) == 0)
        return 0;

    if ((v = VCT_POOL_AllocFrame()) == 0) {
        VCT_AUDIO_FlushReadyQueue(ch->f34);
        VCT_AUDIO_FlushPendingSlot(ch->f34);
        if ((v = VCT_POOL_AllocFrame()) == 0) {
            VCT_AUDIO_FlushAllReadyQueues();
            VCT_AUDIO_FlushPendingAll();
            v = VCT_POOL_AllocFrame();
        }
        if (v == 0)
            return 0;
    }

    dst = &v->buf[sizeof(v->buf)] - (size - 0xc);
    MI_CpuCopy8(hdr->data, dst, size - 0xc);
    v->f11 = ch->f34;
    v->fC = mode;
    v->f474 = dst;
    v->f14 = size - 0xc;
    v->tick = tick;
    v->f10 = id;
    v->f45C = hdr->f5 & 0x80;
    v->f460 = hdr->f8;
    v->f18 = hdr->f6;
    if (VCT_AUDIO_TrackPacketTiming((struct Src *)ch, (struct Pkt *)v) == 0) {
        VCT_POOL_FreeFrame(v);
        return 0;
    }
    VCT_AUDIO_QueuePending((struct Node *)v);
    return 1;
}
