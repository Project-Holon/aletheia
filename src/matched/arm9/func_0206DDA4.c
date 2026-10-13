/*
 * function: NNS_G3dGeBufferOP_N
 * address:  0x0206DDA4
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   gNnsG3dGeState     0x0214BAB4  data
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   MIi_CpuSend32  0x02082AA8  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   NNS_G3dGeWaitSendDL  0x0206DBDC  arm
 */

typedef unsigned int u32;

struct GxList { u32 count; u32 cmds[1]; };
struct GxState { struct GxList *list; volatile u32 unk_04; };
extern struct GxState gNnsG3dGeState;

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 n);
extern void MIi_CpuSend32(const void *src, void *dst, u32 n);
extern void NNS_G3dGeFlushBuffer(void);
extern void NNS_G3dGeWaitSendDL(void);

void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n)
{
    if (gNnsG3dGeState.list != 0) {
        if (gNnsG3dGeState.unk_04 != 0) {
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
        } else if (gNnsG3dGeState.unk_04 != 0) {
            NNS_G3dGeWaitSendDL();
        }
    } else if (gNnsG3dGeState.unk_04 != 0) {
        NNS_G3dGeWaitSendDL();
    }
    *(u32 *)0x04000400 = cmd;
    MIi_CpuSend32(params, (void *)0x04000400, n * 4);
}

