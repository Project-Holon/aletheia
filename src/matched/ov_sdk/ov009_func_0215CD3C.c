/*
 * function: SOCLi_StartupCommandPacketQueue
 * address:  0x0215CD3C
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gSoclConfig   0x021A1CD8  data
 *   g_021AA484   0x021AA484  data
 *   gSoclCmdQueue   0x021AA480  data
 *   OS_InitMessageQueue  0x02085D94  arm
 *   SOCLi_FreeCommandPacket  0x0215CE7C  arm  ov009
 *
 * Allocate one block for `n` records: the first region is the word-aligned
 * n*4 pointer array and the second the word-aligned 0x2c-byte records, both
 * sized through the allocator hook at +0x18 of the object the global points
 * at.  Each record is initialised (SOCLi_FreeCommandPacket) into the second region and
 * the block is published at 0x021AA480.  Returns -1 when allocation fails.
 */

typedef void *(*Alloc1)(int);

extern char gSoclConfig[];
extern char g_021AA484[];
extern char gSoclCmdQueue[];
typedef signed int     s32;
struct OSMessageQueue;
extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern void SOCLi_FreeCommandPacket(void *ptr);

int SOCLi_StartupCommandPacketQueue(int n)
{
    char *base;
    char *p;
    int off;
    int size;
    int i;

    size = (n * 0x2c + 3) & ~3;
    off = (n * 4 + 3) & ~3;

    base = (char *)(*(Alloc1 *)(*(char **)gSoclConfig + 0x18))(size + off);
    if (base == 0)
        return -1;

    OS_InitMessageQueue((struct OSMessageQueue *)g_021AA484, (void **)base, n);

    p = base + off;
    for (i = n; i > 0; i--) {
        SOCLi_FreeCommandPacket(p);
        p += 0x2c;
    }

    *(char **)gSoclCmdQueue = base;
    return 0;
}
