/*
 * file:     nns_g3d_ge.c
 * unit:     yes
 * function: NNS_G3dGeIsBufferExist, NNS_G3dGeSetBuffer, NNS_G3dGeReleaseBuffer, NNS_G3dGeFlushBuffer, NNS_G3dGeWaitSendDL, NNSi_G3dGeSendDLDone, NNS_G3dGeSendDL, NNS_G3dGeBufferOP_N, NNS_G3dGeResetGX
 * address:  0x0206DB24
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0214BAB4      0x0214BAB4  data  a4
 *   gNnsG3dGeState       0x0214BAB4  data
 *   MIi_CpuSend32    0x02082AA8  arm
 *   GXi_DmaId     0x020A84C0  data
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   MI_SendNDmaGXCommandAsyncFast  0x027300F0  arm  twl
 *   MI_SendNDmaGXCommandAsync  0x0272FEF4  arm  twl
 *   MI_SendGXCommandAsyncFast  0x02082960  arm
 *   MI_SendGXCommandAsync  0x02082760  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   G3X_GetClipMtx    0x0207DC98  arm
 *   MTX_Copy44To43_    0x0207BDE0  arm
 *   G3X_GetVectorMtx    0x0207DCC8  arm
 */
#include "../types.h"
#include "../sdk_ioreg_reg.h"
#include "../sdk_ioreg.h"

struct NNSiG3dGeCmdList { u32 count; u32 cmds[1]; };

struct NNSiG3dGeState {
    struct NNSiG3dGeCmdList *list;
    volatile u32 busy;
    u32 useFastDma;
};

typedef void (*MIDmaCallback)(void *arg);

#include "mi_memory.h"
#include "os_emulator.h"
#include "../twl/mi_ndma_gxcommand.h"
extern void MI_SendGXCommandAsyncFast(u32 dma, const void *src, u32 sz, MIDmaCallback cb, void *arg);
extern void MI_SendGXCommandAsync(u32 dma, const void *src, u32 sz, MIDmaCallback cb, void *arg);
#include "g3x.h"
#include "fx_mtx44.h"
int NNS_G3dGeIsBufferExist(void);
void NNS_G3dGeSetBuffer(u32 *cmdBuffer);
void *NNS_G3dGeReleaseBuffer(void);
void NNS_G3dGeFlushBuffer(void);
void NNS_G3dGeWaitSendDL(void);
void NNSi_G3dGeSendDLDone(void *arg);
void NNS_G3dGeSendDL(const u32 *src, u32 sz);
void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
void NNS_G3dGeResetGX(void *clipMtxOut, void *vectorMtxOut);
extern struct NNSiG3dGeState gNnsG3dGeState;
extern u32 GXi_DmaId;      /* GXi_DmaId */

/* NNS_G3dGeIsBufferExist: nonzero when a geometry command buffer is installed. */
int NNS_G3dGeIsBufferExist(void)
{
    return gNnsG3dGeState.list != 0;
}

/*
 */
/* NNS_G3dGeSetBuffer: install the geometry command buffer (empty) if none is set. */
void NNS_G3dGeSetBuffer(u32 *cmdBuffer)
{
    if (gNnsG3dGeState.list == 0) {
        *cmdBuffer = 0;
        gNnsG3dGeState.list = (struct NNSiG3dGeCmdList *)cmdBuffer;
    }
}

/*
 */
/* NNS_G3dGeReleaseBuffer: flush the pending commands, then hand the buffer back. */
void *NNS_G3dGeReleaseBuffer(void)
{
    void *cmdBuffer;

    NNS_G3dGeFlushBuffer();
    cmdBuffer = gNnsG3dGeState.list;
    gNnsG3dGeState.list = 0;
    return cmdBuffer;
}

/*
 * Drains the block described by the global pair at 0x0214BAB4: word 1
 * non-zero means a transfer is still in flight, so wait for it; then word 0's
 * object has its payload (object + 4) filled with 0x04000400 over count*4
 * bytes and its count zeroed.
 *
 * PIN ../2.0/sp2, the address-rematerialisation tell (docs/FRONTEND-PINS.md).
 * The original loads the pool word at 0x0206DBD4 THREE times -- `ldr r0,
 * [pc, #0x48]` at +0004, `ldr r0, [pc, #0x34]` at +0018 and `ldr r0,
 * [pc, #0xc]` at +0040 -- and its prologue is `push {r3, lr}`, i.e. not one
 * callee-saved register is spent.  1.1p1 -O4,p instead materialises the
 * address once into r4 across the MIi_CpuSend32 call, growing the push to
 * `push {r4, lr}` and shortening the tail by one load: 88 bytes against the
 * original's 92, 23 concrete bytes out (the residue docs/notes/
 * pkt_0206DB80.c.txt recorded).  No spelling of the C moves it under 1.1p1:
 * volatile on the array elements, a named local for the head pointer and the
 * fully spelled-out `g[0][0]` form all give the same r4.  Under the pin the
 * same C is 92 bytes, 0 mismatches.
 *
 */
void NNS_G3dGeFlushBuffer(void)
{
    if (gNnsG3dGeState.busy != 0)
        NNS_G3dGeWaitSendDL();
    if (gNnsG3dGeState.list != 0 && gNnsG3dGeState.list->count != 0) {
        MIi_CpuSend32(gNnsG3dGeState.list->cmds, (void *)REG_GXFIFO_ADDR, gNnsG3dGeState.list->count * 4);
        gNnsG3dGeState.list->count = 0;
    }
}

/*
 * Spin on the word at +4 of the same global NNS_G3dGeSetBuffer/60 hold the head
 * pointer in.  The `volatile` is load-bearing: without it mwccarm proves the
 * word cannot change inside the empty loop and collapses the re-read into a
 * single load plus a self-branch (24 bytes against the original's 20, and the
 * load lands at +0 instead of +4).
 */
void NNS_G3dGeWaitSendDL(void)
{
    while (gNnsG3dGeState.busy != 0)
        ;
}

/*
 * NitroSystem G3D gecom.c: the GX-command DMA completion callback that
 * NNS_G3dGeSendDL (NNS_G3dGeSendDL) passes to the async DMA start; it clears
 * the in-flight word it is handed (&gNnsG3dGeState.busy).  A 12-byte leaf with
 * no lr save, so disasm.py folds it into NNS_G3dGeWaitSendDL's listing extent;
 * filed as the witness that clears NNS_G3dGeSendDL's ABS32 site once
 * 0x0206DBF4 is seeded in layout/function_starts.txt.
 */
void NNSi_G3dGeSendDLDone(void *arg)
{
    *(volatile u32 *)arg = 0;
}

/*
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
 */
void NNS_G3dGeSendDL(const u32 *src, u32 sz)
{
    if (sz < 0x100 || GXi_DmaId == (u32)-1) {
        NNS_G3dGeBufferOP_N(*src, src + 1, (sz >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    gNnsG3dGeState.busy = 1;
    if (gNnsG3dGeState.useFastDma) {
        if (OS_IsRunOnTwl()) {
            u32 id = GXi_DmaId;
            u32 dma = id > 3 ? (u32)-1 : id;
            if (dma == (u32)-1)
                MI_SendNDmaGXCommandAsyncFast((unsigned int)(id > 3 ? id - 4 : (u32)-1), (uptr)src, (unsigned int)sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
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
                MI_SendNDmaGXCommandAsync((unsigned int)(id > 3 ? id - 4 : (u32)-1), (uptr)src, (unsigned int)sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
            else
                MI_SendGXCommandAsync(dma, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
        } else {
            MI_SendGXCommandAsync(GXi_DmaId > 3 ? (u32)-1 : GXi_DmaId, src, sz, NNSi_G3dGeSendDLDone, (void *)&gNnsG3dGeState.busy);
        }
    }
}

/*
 * NitroSystem G3D NNS_G3dGeBufferOP_N (gecom.c): append op + num argument
 * words to the current geometry command buffer while a display-list send is
 * in flight and the buffer has room (0xc0 words); otherwise flush the buffer
 * (NNS_G3dGeFlushBuffer) or wait out the send (NNS_G3dGeWaitSendDL), then write op to
 * GXFIFO 0x04000400 and send the arguments after it (MIi_CpuSend32).
 *
 * The last 46 bytes were one hoisted load: the fix is that the in-flight word
 * at +4 is a VOLATILE FIELD of the one global (never CSE'd between the
 * list != 0 and list == 0 arms), not a second volatile declaration of the
 * same address. Under dsi/1.1p1 the same C pushes {r3-r7,lr}; pinned
 * ../2.0/sp2 as the rest of the cluster.
 */
void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n)
{
    if (gNnsG3dGeState.list != 0) {
        if (gNnsG3dGeState.busy != 0) {
            u32 count = gNnsG3dGeState.list->count;
            if (count + 1 + n <= 0xc0) {
                gNnsG3dGeState.list->count = count + 1;
                gNnsG3dGeState.list->cmds[count] = cmd;
                if (n == 0)
                    return;
                MIi_CpuCopyFast(params,
                              &gNnsG3dGeState.list->cmds[gNnsG3dGeState.list->count],
                              n * 4);
                gNnsG3dGeState.list->count += n;
                return;
            }
        }
        if (gNnsG3dGeState.list->count != 0) {
            NNS_G3dGeFlushBuffer();
        } else if (gNnsG3dGeState.busy != 0) {
            NNS_G3dGeWaitSendDL();
        }
    } else if (gNnsG3dGeState.busy != 0) {
        NNS_G3dGeWaitSendDL();
    }
    *(u32 *)0x04000400 = cmd;
    MIi_CpuSend32(params, (void *)REG_GXFIFO_ADDR, n * 4);
}

/*
 * The 3D-engine reset path: drain the pending display list (NNS_G3dGeFlushBuffer),
 * zero GXFIFO's control words at 0x04000440/0x04000444/0x04000454, then, if a
 * matrix block was given, spin G3X_GetClipMtx on a 0x40-byte stack scratch
 * until it reports ready and hand the pair to MTX_Copy44To43_; if a second block
 * was given, spin G3X_GetVectorMtx on it; finally write 1 to 0x04000448 and 2 to
 * 0x04000440 (the store to 0x04000440 is spelled `str r0, [r1, #-8]` off the
 * 0x04000448 pool word, so the two are one base in the original too).
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, and the sibling
 * src/matched/NNS_G3dGeFlushBuffer.c).
 *
 */
void NNS_G3dGeResetGX(void *clipMtxOut, void *vectorMtxOut)
{
    u32 clipMtx[0x10];

    NNS_G3dGeFlushBuffer();
    *(u32 *)0x04000440 = 0;
    *(u32 *)0x04000444 = 0;
    *(u32 *)0x04000454 = 0;
    if (clipMtxOut != 0) {
        while (G3X_GetClipMtx((MtxFx44 *)clipMtx) != 0)
            ;
        MTX_Copy44To43_((MtxFx44 *)clipMtx, clipMtxOut);
    }
    if (vectorMtxOut != 0) {
        while (G3X_GetVectorMtx(vectorMtxOut) != 0)
            ;
    }
    *(u32 *)0x04000448 = 1;
    *(u32 *)0x04000440 = 2;
}
