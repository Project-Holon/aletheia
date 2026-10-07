/*
 * file:     unit_021F636C.c
 * unit:     yes
 * function: func_021F636C, func_021F6380, func_021F63E8
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
 *   func_02087988  0x02087988  arm
 *   func_02088234  0x02088234  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned long u32;

typedef unsigned char u8;

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

extern void MI_CpuFill8(void *dst, int val, u32 len);
extern u32 func_02087988(void);
extern u32 func_0208799C(u32 state);
extern void func_02088234(void);
extern void func_02082D44(void *src, void *dst, u32 size);
void MBi_InitCache(void *pl);
void func_021F6380(MBiCacheList *pl, u32 src, u32 len, void *ptr, u32 state);
int func_021F63E8(MBiCacheList *pl, u32 src, void *dst, u32 len);


void MBi_InitCache(void *pl)
{
    MI_CpuFill8(pl, 0, 0x70);
}


/*
 * sdk:      MBi_AttachCacheBuffer (libmb.TWL.HYB.a mb_cache.o)
 */
void func_021F6380(MBiCacheList *pl, u32 src, u32 len, void *ptr, u32 state)
{
    u32 bak_cpsr;
    MBiCacheInfo *pi;

    bak_cpsr = func_02087988();
    for (pi = pl->list; ; pi++) {
        if (pi >= &pl->list[4])
            func_02088234();
        if (pi->state == 0) {
            pi->src = src;
            pi->len = len;
            pi->ptr = ptr;
            pi->state = state;
            break;
        }
    }
    func_0208799C(bak_cpsr);
}


/*
 * sdk:      MBi_ReadFromCache (libmb.TWL.HYB.a mb_cache.o)
 */
int func_021F63E8(MBiCacheList *pl, u32 src, void *dst, u32 len)
{
    int ret;
    u32 bak_cpsr;
    MBiCacheInfo *pi;
    int ofs;

    ret = 0;
    bak_cpsr = func_02087988();
    for (pi = pl->list; pi < &pl->list[4]; pi++) {
        if (pi->state < 2)
            continue;
        ofs = src - pi->src;
        if (ofs < 0)
            continue;
        if (ofs + len > pi->len)
            continue;
        func_02082D44((u8 *)pi->ptr + ofs, dst, len);
        pl->f0 = 0;
        ret = 1;
        break;
    }
    func_0208799C(bak_cpsr);
    return ret;
}
