/*
 * function: DSP_HookPipeNotification
 * address:  0x027070DC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02734528  0x02734528  data twl a2
 *   data_0273452C  0x0273452C  data twl a2
 *   data_02734534  0x02734534  data twl a2
 *   data_02734554  0x02734554  data twl a2
 *   DSP_RecvDataIsReadyCore  0x02705008  arm twl a2
 *   DSP_RecvDataCore  0x0270505C  arm twl a2
 *   DSP_GetSemaphoreCore  0x02705284  arm twl a2
 *   DSP_ClearSemaphoreCore  0x02705294  arm twl a2
 *   DSPi_NotifyFileIOUpdation  0x02706B60  arm twl a2
 *   DSP_LoadPipe  0x02706D44  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef void (*DspCb)(void *, int, int);

typedef struct DspIoState {
    u32 f0;
    u32 f4;
    u32 f8;
    DspCb callback;
} DspIoState;

typedef struct DspReq {
    u32 w0;
    u32 w1;
    u16 flags;
} DspReq;

extern DspIoState data_02734528;
extern DspCb data_02734534[8];
extern void *data_02734554[8];
extern u32 data_0273452C;

extern int OS_IsRunOnTwl(void);
extern void OS_WakeupThread(void *q);
extern u16 DSP_GetSemaphoreCore(void);
extern u32 DSP_RecvDataIsReadyCore(u32 ch);
extern u16 DSP_RecvDataCore(u32 ch);
extern void DSP_ClearSemaphoreCore(u16 v);
extern void DSP_LoadPipe(DspReq *req, int ch, int flag);
extern void DSPi_NotifyFileIOUpdation(int ch);

void DSP_HookPipeNotification(void) {
    DspReq req;
    int ch;
    int flag;
    int v;
    while ((OS_IsRunOnTwl() == 1 ? DSP_GetSemaphoreCore() : 0) & 0x8000
           || (OS_IsRunOnTwl() == 1 ? DSP_RecvDataIsReadyCore(2) : 0)) {
        if (OS_IsRunOnTwl() == 1) {
            DSP_ClearSemaphoreCore(0x8000);
        }
        while (OS_IsRunOnTwl() == 1 ? DSP_RecvDataIsReadyCore(2) : 0) {
            if (data_02734528.f0 == 0) {
                data_02734528.f0 = (OS_IsRunOnTwl() == 1 ? DSP_RecvDataCore(2) : 0) << 1;
            } else {
                v = OS_IsRunOnTwl() == 1 ? DSP_RecvDataCore(2) : 0;
                ch = v >> 1;
                flag = v & 1;
                if (ch >= 0 && ch < 8) {
                    if (data_02734534[ch] != 0) {
                        data_02734534[ch](data_02734554[ch], ch, flag);
                    } else {
                        DSP_LoadPipe(&req, ch, flag);
                        if (flag == 0 && (req.flags & 0x100)) {
                            DSPi_NotifyFileIOUpdation(ch);
                        }
                    }
                }
            }
            OS_WakeupThread(&data_0273452C);
        }
    }
}
