/*
 * function: func_021F63E8
 * address:  0x021F63E8
 * packet:   pkt_ov107_021F63E8
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ReadFromCache (libmb.TWL.HYB.a mb_cache.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuCopy8  0x02082D44  arm
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
extern void MI_CpuCopy8(void *src, void *dst, u32 size);

int func_021F63E8(MBiCacheList *pl, u32 src, void *dst, u32 len)
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
        pl->f0 = 0;
        ret = 1;
        break;
    }
    OS_RestoreInterrupts(bak_cpsr);
    return ret;
}
