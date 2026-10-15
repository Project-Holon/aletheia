/*
 * function: AESi_InitLock
 * address:  0x02707AEC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02735B20  0x02735B20  data
 *   gMslRefToken  0x02150FEC  data  arm9
 */

typedef unsigned int u32;
typedef struct OSThread OSThread;
typedef struct {
    OSThread *head;
    OSThread *tail;
} OSThreadQueueLike;
typedef struct {
    OSThread *owner;
    u32 count;
    OSThreadQueueLike queue;
} SysLockLike;
typedef struct {
    u32 reserved;
    OSThread *current;
} ThreadInfoLike;
extern SysLockLike g_02735B20;
extern ThreadInfoLike gMslRefToken;

void AESi_InitLock(void)
{
    g_02735B20.queue.tail = 0;
    g_02735B20.queue.head = 0;
    g_02735B20.owner = 0;
    g_02735B20.count = 0;
}
