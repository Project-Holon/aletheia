/*
 * file:     mb_cache.c
 * unit:     yes
 * function: MBi_InitCache, MBi_AttachCacheBuffer, MBi_ReadFromCache
 * address:  0x021F636C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../types.h"

#include "../sdk_mb.h"

extern void MI_CpuFill8(void *dst, int val, u32 len);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void OS_Terminate(void);
extern void MI_CpuCopy8(void *src, void *dst, u32 size);
void MBi_InitCache(void *pl);
void MBi_AttachCacheBuffer(MBiCacheList *pl, u32 src, u32 len, void *ptr, u32 state);
int MBi_ReadFromCache(MBiCacheList *pl, u32 src, void *dst, u32 len);

void MBi_InitCache(void *pl)
{
    MI_CpuFill8(pl, 0, 0x70);
}

/*
 * sdk:      MBi_AttachCacheBuffer (libmb.TWL.HYB.a mb_cache.o)
 */
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

/*
 * sdk:      MBi_ReadFromCache (libmb.TWL.HYB.a mb_cache.o)
 */
int MBi_ReadFromCache(MBiCacheList *pl, u32 src, void *dst, u32 len)
{
    int ret;
    u32 bak_cpsr;
    MBiCacheInfo *pi;
    int ofs;

    ret = 0;
    bak_cpsr = OS_DisableInterrupts();
    for (pi = pl->list; pi < &pl->list[4]; pi++) {
        if (pi->state < 2)
            continue;
        ofs = src - pi->src;
        if (ofs < 0)
            continue;
        if (ofs + len > pi->len)
            continue;
        MI_CpuCopy8((u8 *)pi->ptr + ofs, dst, len);
        pl->lifetime = 0;
        ret = 1;
        break;
    }
    OS_RestoreInterrupts(bak_cpsr);
    return ret;
}
