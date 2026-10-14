/*
 * function: MBi_AttachCacheBuffer
 * address:  0x021F6380
 * packet:   pkt_ov107_021F6380
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_AttachCacheBuffer (libmb.TWL.HYB.a mb_cache.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u32 src;
    u32 len;
    void *ptr;
    u32 state;
} MBiCacheInfo;

typedef struct {
    u32 f0;
    u8 pad[0x2C];
    MBiCacheInfo list[4];
} MBiCacheList;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void OS_Terminate(void);

void MBi_AttachCacheBuffer(MBiCacheList *pl, u32 src, u32 len, void *ptr, u32 state)
{
    u32 bak_cpsr;
    MBiCacheInfo *pi;

    bak_cpsr = OS_DisableInterrupts();
    for (pi = pl->list; ; pi++) {
        if (pi >= &pl->list[4])
            OS_Terminate();
        if (pi->state == 0) {
            pi->src = src;
            pi->len = len;
            pi->ptr = ptr;
            pi->state = state;
            break;
        }
    }
    OS_RestoreInterrupts(bak_cpsr);
}
