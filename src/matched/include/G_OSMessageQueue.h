#ifndef ALETHEIA_G_OSMESSAGEQUEUE_H
#define ALETHEIA_G_OSMESSAGEQUEUE_H
/* g_021DCE40 (arm9) */
struct OSMessageQueue {
    void *queueSend_head;
    void *queueSend_tail;
    void *queueReceive_head;
    void *queueReceive_tail;
    void **msgArray;
    long msgCount;
    long firstIndex;
    long usedCount;
};
#endif
