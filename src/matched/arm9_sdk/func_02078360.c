/*
 * function: FS_InitArchive
 * address:  0x02078360
 * packet:   pkt_02078360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_InitArchive (fs_archive.o)
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 */

#define NULL ((void *)0)

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive {
    unsigned long name;
    struct FSArchive *next;
    void *list;
    OSThreadQueue queue;
    unsigned char rest[0x5C - 0x14];
} FSArchive;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void FS_InitArchive(FSArchive *p_arc)
{
    MI_CpuFill8(p_arc, 0, sizeof(FSArchive));
    p_arc->queue.head = p_arc->queue.tail = NULL;
}
