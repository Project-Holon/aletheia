/*
 * function: NNS_G3dGeSendDL
 * address:  0x0206DC00
 * packet:   pkt_0206DC00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D NNS_G3dGeSendDL (gecom.c): send a display list. Under 256
 * bytes, or with no GX DMA channel (GXi_DmaId at 0x020A84C0 == -1), it goes
 * through NNS_G3dGeBufferOP_N (NNS_G3dGeBufferOP_N) one command word + args.
 * Otherwise flush the buffer, raise the in-flight word at +4 and start an
 * async GX-command DMA with the completion callback NNSi_G3dGeSendDLDone
 * (clears *arg) and arg = &gNnsG3dGeState.busy. The +8 word selects the Fast
 * variant; on TWL hardware (OS_IsRunOnTwl) an id above 3 is an NDMA channel
 * id - 4 handled by the TWL-only routines at 0x027300F0 / 0x0272FEF4.
 *
 * EXACT under ../2.0/sp2 (dsi/1.1p1 pushes {r3-r8,lr} and is 12 bytes
 * short), 14 of 14 relocations resolved (wave 19, 2026-09-24):
 *   - PC24 0x027300F0 and 0x0272FEF4: TWL code, region `twl` (the DSi-mode
 *     autoload block of arm9i.bin), named with the `twl` token. Both are
 *     traced ARM function starts in asm/twl/twl.s, which exists only with a
 *     user-supplied DSi key (see tools/modcrypt.py). No branch outside this
 *     function targets either one, so `label` refuses them; they resolve as
 *     `sole-ref/code` over the twl listing (attest_sole_ref_twl_code()).
 *   - ABS32 0x0206DBF4: resolves as `matched` (src/matched/NNSi_G3dGeSendDLDone.c,
 *     shard pkt_0206DC00).
 *
 * symbols:
 *   GXi_DmaId     0x020A84C0  data
 *   gNnsG3dGeState     0x0214BAB4  data
 *   NNSi_G3dGeSendDLDone  0x0206DBF4  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   MI_SendNDmaGXCommandAsyncFast  0x027300F0  arm  twl
 *   MI_SendNDmaGXCommandAsync  0x0272FEF4  arm  twl
 *   MI_SendGXCommandAsyncFast  0x02082960  arm
 *   MI_SendGXCommandAsync  0x02082760  arm
 */

#include "../include/G_GeState.h"

typedef unsigned int u32;

struct GxList { u32 count; u32 cmds[1]; };
extern struct GeState gNnsG3dGeState;
extern u32 GXi_DmaId;      /* GXi_DmaId */

typedef void (*MICallback)(void *arg);
extern void NNSi_G3dGeSendDLDone(void *arg);
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void NNS_G3dGeFlushBuffer(void);
extern int  OS_IsRunOnTwl(void);
extern void MI_SendNDmaGXCommandAsyncFast(u32 ndma, const void *src, u32 sz, MICallback cb, void *arg);
extern void MI_SendNDmaGXCommandAsync(u32 ndma, const void *src, u32 sz, MICallback cb, void *arg);
extern void MI_SendGXCommandAsyncFast(u32 dma, const void *src, u32 sz, MICallback cb, void *arg);
extern void MI_SendGXCommandAsync(u32 dma, const void *src, u32 sz, MICallback cb, void *arg);

void NNS_G3dGeSendDL(const u32 *src, u32 sz)
{
    if (sz < 0x100 || GXi_DmaId == (u32)-1) {
        NNS_G3dGeBufferOP_N(*src, src + 1, (sz >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    gNnsG3dGeState.busy = 1;
    if (gNnsG3dGeState.f8) {
        if (OS_IsRunOnTwl()) {
            u32 id = GXi_DmaId;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                MI_SendNDmaGXCommandAsyncFast(id > 3 ? id - 4 : (u32)-1, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
            else
                MI_SendGXCommandAsyncFast(dma, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
        } else {
            MI_SendGXCommandAsyncFast(GXi_DmaId > 3 ? (u32)-1 : GXi_DmaId, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
        }
    } else {
        if (OS_IsRunOnTwl()) {
            u32 id = GXi_DmaId;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                MI_SendNDmaGXCommandAsync(id > 3 ? id - 4 : (u32)-1, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
            else
                MI_SendGXCommandAsync(dma, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
        } else {
            MI_SendGXCommandAsync(GXi_DmaId > 3 ? (u32)-1 : GXi_DmaId, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
        }
    }
}
