/*
 * function: AOSSi_InitLocal
 * address:  0x021B84E4
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aosslink_bss          0x021DCE20  data
 *   aoss_mq               0x021DCE40  data
 *   aoss_msgArray         0x021DCE30  data
 *   aoss_apc_callback     0x021B84BC  thumb
 *   OS_InitMessageQueue   0x02085D94  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   APC_Init              0x021B8F80  thumb
 *   OS_ReceiveMessage     0x02085E50  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aosslink.o), symbol AOSSi_InitLocal (name from the vendor object).
 * aosslink.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B84E4.c \
 *       --func AOSSi_InitLocal --addr 0x021B84E4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../include/G_OSMessageQueue.h"
#include "../include/G_AOSSLINK_BSS.h"

typedef struct _OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

typedef struct OSMessageQueue OSMessageQueue;

/*
 * aosslink.o's .bss statics from 0x021DCE20: the vendor object addresses AOSSi_Free and
 * aoss_workbuffer through AOSSi_Alloc's pool word plus an offset, so the four words are
 * declared as one object in the object's own order; member names are the vendor symbols.
 */
typedef struct {
    void *(*AOSSi_Alloc)(unsigned long size);
    void  (*aoss_callback)(int event);
    void   *aoss_workbuffer;
    void  (*AOSSi_Free)(void *ptr);
} AOSSLINK_BSS;

extern struct AOSSLINK_BSS aosslink_bss;

extern struct OSMessageQueue aoss_mq;
extern void *aoss_msgArray[4];
extern void aoss_apc_callback(int event);
extern void OS_InitMessageQueue(OSMessageQueue *mq, void **msgArray, long msgCount);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern int OS_ReceiveMessage(OSMessageQueue *mq, void **msg, long flags);

int AOSSi_InitLocal(void *(*alloc)(unsigned long), void (*free)(void *))
{
    void *msg;
    unsigned long enabled;
    int loop_flag;

    loop_flag = 1;
    OS_InitMessageQueue(&aoss_mq, aoss_msgArray, 4);
    if (alloc == 0 || free == 0)
        return -1;
    enabled = OS_DisableInterrupts();
    aosslink_bss.AOSSi_Alloc = alloc;
    aosslink_bss.AOSSi_Free = free;
    OS_RestoreInterrupts(enabled);
    aosslink_bss.aoss_workbuffer = aosslink_bss.AOSSi_Alloc(0x5890);
    if (aosslink_bss.aoss_workbuffer == 0)
        return -1;
    if (APC_Init((void (*)(int, void *))aoss_apc_callback, aosslink_bss.aoss_workbuffer, 0x5890) == 0)
        loop_flag = 0;
    while (loop_flag) {
        OS_ReceiveMessage(&aoss_mq, &msg, 1);
        switch ((int)msg) {
        case 4:
        case 5:
            break;
        case 6:
            return 0;
        case 0:
        case 1:
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        default:
            loop_flag = 0;
            break;
        }
    }
    aosslink_bss.AOSSi_Free(aosslink_bss.aoss_workbuffer);
    return -1;
}
