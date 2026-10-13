/*
 * function: func_0208B8B0
 * address:  0x0208B8B0
 * packet:   pkt_02087AE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_02153000               0x02153000  data
 *   PXI_Init            0x02088498  arm
 *   PXI_IsCallbackReady      0x020885EC  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   SVC_WaitByLoop           0x02004490  thumb
 *   PMi_CommonCallback       0x0208B950  arm
 *
 * TwlSDK libspi pm.o, the init entry (PM_Init shape): a once-only latch on
 * the module work's +0x00 halfword, clear the two callback-list heads at
 * +0x30/+0x34 and the shared word 0x02FFF684, run the lock setup behind the
 * veneer at 0x02088498, spin with SVC_WaitByLoop(100) until the ARM7 side's
 * PM FIFO tag (8) is ready, install PMi_CommonCallback, then seed +0x10 and
 * +0x0c from one read of the VBlank counter (0x02FFFC3C).
 *
 * The 9-byte r0/r1 swap in docs/notes/pkt_0208B8B0.c.txt was the last
 * statement: the counter is READ ONCE (volatile, through an inline
 * OS_GetVBlankCount) and assigned in a chain, so its address is materialised
 * before the work pointer.  0x02FFF684 and 0x02FFFC3C are fixed shared-memory
 * addresses, written as cast constants, so the site that note left without a
 * witness is not a relocation at all.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0208B8B0.c \
 *       --func func_0208B8B0 --addr 0x0208B8B0 --arm --cc 1.1p1
 */
typedef unsigned char u8; typedef unsigned short u16;
typedef unsigned int  u32; typedef volatile u32 vu32; typedef int BOOL;
struct S { u16 f00; u8 pad_02[0x0a]; u32 f0c; u32 f10;
           u8 pad_14[0x1c]; u32 f30; u32 f34; };
extern struct S s_02153000;
extern void PXI_Init(void);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void SVC_WaitByLoop(int count);
extern void PMi_CommonCallback(int tag, u32 data, BOOL err);
static inline u32 OS_GetVBlankCount(void) { return *(vu32 *)0x02FFFC3C; }
void func_0208B8B0(void)
{
    if (s_02153000.f00) return;
    s_02153000.f00 = 1;
    s_02153000.f30 = 0;
    s_02153000.f34 = 0;
    *(vu32 *)0x02FFF684 = 0;
    PXI_Init();
    while (!PXI_IsCallbackReady(8, 1)) {
        SVC_WaitByLoop(100);
    }
    PXI_SetFifoRecvCallback(8, PMi_CommonCallback);
    s_02153000.f0c = s_02153000.f10 = OS_GetVBlankCount();
}
