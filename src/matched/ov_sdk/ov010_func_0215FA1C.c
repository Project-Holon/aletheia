/*
 * function: DSPi_WaitForPipe
 * address:  0x0215FA1C
 * packet:   pkt_ov010_0215FA1C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      DSPi_WaitForPipe (dsp_pipe.o)
 *
 * symbols:
 *   OS_SleepThread     0x02034ac4  arm
 *   DSP_SyncPipe       0x0218571c  thumb
 *   DSPiBlockingQueue  0x00000014  data
 */

struct DSPPipe;
struct _OSThreadQueue;

void OS_SleepThread(struct _OSThreadQueue *queue);
void DSP_SyncPipe(struct DSPPipe *pipe);
extern struct _OSThreadQueue DSPiBlockingQueue;

static void DSPi_WaitForPipe(struct DSPPipe *pipe)
{
    OS_SleepThread(&DSPiBlockingQueue);
    DSP_SyncPipe(pipe);
}
