/*
 * function: AOSSi_Disconnect
 * address:  0x021B8640
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_mq            0x021DCE40  data
 *   APC_Disconnect     0x021B8E6C  thumb
 *   OS_ReceiveMessage  0x02085E50  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aosslink.o), symbol AOSSi_Disconnect (name from the vendor object).
 * aosslink.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8640.c \
 *       --func AOSSi_Disconnect --addr 0x021B8640 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct _OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    void        **msgArray;
    long          msgCount;
    long          firstIndex;
    long          usedCount;
} OSMessageQueue;

extern OSMessageQueue aoss_mq;
extern int APC_Disconnect(void);
extern int OS_ReceiveMessage(OSMessageQueue *mq, void **msg, long flags);

int AOSSi_Disconnect(void)
{
    void *msg;
    int loop_flag;
    int rc;

    rc = -1;
    if (APC_Disconnect() != 0) {
        do {
            OS_ReceiveMessage(&aoss_mq, &msg, 1);
            if ((int)msg == 14) {
                loop_flag = 0;
                rc = 0;
            } else {
                loop_flag = 0;
            }
        } while (loop_flag);
    }
    return rc;
}
