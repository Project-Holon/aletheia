/*
 * function: AOSSi_EndLocal
 * address:  0x021B85A8
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
 *   APC_End               0x021B8EA4  thumb
 *   OS_ReceiveMessage     0x02085E50  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aosslink.o), symbol AOSSi_EndLocal (name from the vendor object).
 * aosslink.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B85A8.c \
 *       --func AOSSi_EndLocal --addr 0x021B85A8 --region ov016 --cc ../2.0/sp1p2 --thumb
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
extern int APC_End(void);
extern int OS_ReceiveMessage(OSMessageQueue *mq, void **msg, long flags);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

int AOSSi_EndLocal(void)
{
    void *msg;
    unsigned long enabled;
    int loop_flag;
    int rc;

    loop_flag = 1;
    rc = -1;
    if (aosslink_bss.AOSSi_Free == 0)
        return rc;
    if (APC_End() == 0)
        return -1;
    while (loop_flag) {
        OS_ReceiveMessage(&aoss_mq, &msg, 1);
        switch ((int)msg) {
        case 4:
        case 5:
            break;
        case 20:
            loop_flag = 0;
            rc = 0;
            aosslink_bss.AOSSi_Free(aosslink_bss.aoss_workbuffer);
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        default:
            loop_flag = 0;
            break;
        }
    }
    enabled = OS_DisableInterrupts();
    aosslink_bss.AOSSi_Alloc = 0;
    aosslink_bss.AOSSi_Free = 0;
    OS_RestoreInterrupts(enabled);
    return rc;
}
