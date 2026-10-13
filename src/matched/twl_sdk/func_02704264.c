/*
 * function: FATFSi_WaitForRequest
 * address:  0x02704264
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   DAT_02734428   0x02734428  data twl
 *   DAT_02734420   0x02734420  data twl
 *   OS_DisableInterrupts  0x02087988  arm twl
 *   func_020879EC  0x020879EC  arm twl
 *   PXIi_HandlerRecvFifoNotEmpty  0x02088688  arm twl
 *   SVC_WaitByLoop  0x02004490  thumb twl
 *   OS_SleepThread  0x020857B0  arm twl
 *   OS_RestoreInterrupts  0x0208799C  arm twl
 *   DAT_0273444c   0x0273444c  data twl
 */

typedef unsigned int u32;

typedef struct FsNode {
    u32 f00[3];
    struct FsNode *next;
} FsNode;

extern FsNode *DAT_02734428;
extern u32 DAT_02734420[];
extern u32 OS_DisableInterrupts(void);
extern u32 func_020879EC(void);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern void SVC_WaitByLoop(u32);
extern void OS_SleepThread(u32 *);
extern void OS_RestoreInterrupts(u32);
extern u32 DAT_0273444c[];

void FATFSi_WaitForRequest(FsNode *a0) {
    u32 busy = 1;
    while ((busy != 0) ? 1 : 0) {
        u32 ime = OS_DisableInterrupts();
        /* the list is shared: every access rereads it */
        FsNode * volatile *pp = &DAT_02734428;
        FsNode *p;
        while (((p = *pp) != 0) ? 1 : 0) {
            if (*pp == a0) {
                busy = 0;
                *pp = (*pp)->next;
                a0->next = 0;
                break;
            }
            pp = &(*pp)->next;
        }
        if (busy != 0) {
            if (func_020879EC() == 0x12) {
                PXIi_HandlerRecvFifoNotEmpty();
                SVC_WaitByLoop(10000);
            } else {
                OS_SleepThread(DAT_02734420);
            }
        }
        OS_RestoreInterrupts(ime);
    }
}
