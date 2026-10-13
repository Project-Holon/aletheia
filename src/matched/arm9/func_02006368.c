/*
 * function: GFL_USE_StopLoaderThread
 * address:  0x02006368
 * packet:   pkt_02006368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _SndState     0x020AA260  data
 *   _WorkerThread     0x020AA354  data
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_DestroyThread  0x020855BC  arm
 *
 * Deactivates background task: checks _SndState.active, verifies status
 * via OS_IsThreadTerminated(&_WorkerThread), terminates via OS_DestroyThread, and resets active flag.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_StopLoaderThread.c \
 *       --func GFL_USE_StopLoaderThread --addr 0x02006368 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct StructA {
    u8 pad[0x14];
    u32 active;
};

extern struct StructA _SndState;
extern u8 _WorkerThread[];

extern int OS_IsThreadTerminated(void *arg);
extern void OS_DestroyThread(void *arg);

void GFL_USE_StopLoaderThread(void)
{
    if (_SndState.active != 0) {
        if (OS_IsThreadTerminated(_WorkerThread) == 0) {
            OS_DestroyThread(_WorkerThread);
            _SndState.active = 0;
        }
    }
}
