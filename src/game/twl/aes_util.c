/*
 * file:     aes_util.c
 * unit:     yes
 * function: CallbackForJpeg, AESi_InitRand, AESi_Rand, AESi_SignForJpeg, AESi_VerifySignForJpeg
 * address:  0x02707558
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libaes.TWL.HYB.a aes_util.o
 *
 * symbols:
 *   data_02735AE0  0x02735AE0  data twl a2
 *   data_02735AE4  0x02735AE4  data twl a2
 *   data_02735AE8  0x02735AE8  data twl a2
 *   data_02735AEC  0x02735AEC  data twl a2
 *   data_02735B00  0x02735B00  data twl a2
 *   AESi_SeedRand  0x0270741C  arm
 *   AESi_CalcMac  0x027074B0  arm
 *   AESi_PxiSendFirst  0x02707994  arm
 *   AESi_Lock  0x02707B68  arm
 *   AESi_Unlock  0x02707BDC  arm
 *   AESi_RandUnit  0x02707458  arm
 */
#include "../types.h"

#include "../sdk_os.h"

typedef struct OSEvent OSEventLike;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} RandContext;

/*
 * The .bss of this unit (0x02735AE0..0x02735B20). The pool loads one
 * address and uses offsets, so these are initialised statics addressed from
 * the .bss base, not one struct. Evidence: in AESi_InitRand both stores to
 * them come before the stores to ctx. The alias analysis gives that order
 * only for a 4-byte base object; with a struct, the store at offset 0 moves
 * after the ctx stores. mwccarm lays out this definition order as
 * AE0, AE4, AE8, AEC, B00.
 */
static u32 data_02735AE0 = 0;      /* initialised flag */
static u32 data_02735AE8 = 0;      /* bytes left in data_02735B00 */
static u32 data_02735AE4 = 0;
static u8 data_02735AEC[0x10] = {0};
static u8 data_02735B00[0x20] __attribute__((aligned(32))) = {0};
#include "../arm9/os_event.h"
#include "../arm9/os_tick.h"
#include "../arm9/os_entropy.h"
#include "../arm9/dgt_sha1.h"
#include "../arm9/mi_memory.h"
#include "aes_core.h"
#ifdef __MWERKS__
extern void AESi_PxiSendFirst(int tag, u32 a, u32 b);
#else
#include "aes_fifo.h"
#endif
#ifdef __MWERKS__
extern void AESi_Lock(void);
extern void AESi_Unlock(void);
#else
#include "aes_lock.h"
#endif

static void CallbackForJpeg(u32 mask, OSEventLike *ev)
{
    OS_SignalEvent(ev, mask);
}

void AESi_InitRand(void) {
    RandContext ctx;
    u32 entropy[8];
    u32 digest[5];
    u32 i;

    OS_InitTick();
    data_02735AE8 = 0;
    data_02735AE0 = 1;
    ctx.x = (u64)(u32)&ctx | ((u64)(u32)&ctx << 32);
    ctx.mul = 0x5D588B656C078965ULL;
    ctx.add = 0x00269EC3ULL;
    OS_GetLowEntropyData(entropy);
    MATH_CalcSHA1(digest, entropy, 0x20);
    for (i = 0; i < 8; i++) {
        ctx.x = ctx.mul * ctx.x + ctx.add;
        entropy[i] = (u32)(ctx.x >> 32);
    }
    AESi_SeedRand(digest);
    for (i = 0; i < 5; i++) {
        ctx.x = ctx.mul * ctx.x + ctx.add;
        digest[i] = (u32)(ctx.x >> 32);
    }
}

u32 AESi_Rand(u8 *dst, u32 size) {
    u32 count;
    u32 pos;
    u32 r;

    if (data_02735AE0 == 0) {
        AESi_InitRand();
    }
    count = data_02735AE8;
    if (count != 0) {
        if (count > size) {
            count = size;
        }
        data_02735AE8 -= count;
        pos = data_02735AE8;
        MI_CpuCopy8(data_02735B00 + pos, dst, count);
        size -= count;
        dst += count;
    }
    while (size >= 0x10) {
        r = AESi_RandUnit(data_02735B00);
        if (r != 1) {
            return r;
        }
        MI_CpuCopy8(data_02735B00, dst, 0x10);
        dst += 0x10;
        size -= 0x10;
    }
    if (size != 0) {
        r = AESi_RandUnit(data_02735B00);
        if (r != 1) {
            return r;
        }
        pos = 0x10 - size;
        data_02735AE8 = pos;
        MI_CpuCopy8(data_02735B00 + pos, dst, size);
    }
    return 1;
}

int AESi_SignForJpeg(u8 *sign, u32 data, u32 length)
{
    OSEventLike ev;
    int r;

    AESi_Lock();
    if (data_02735AE0 == 0) {
        AESi_InitRand();
    }
    OS_InitEvent(&ev);
    r = AESi_Rand(sign, 0xC);
    if (r != 1) {
        return r;
    }
    do {
        if (data_02735AE4 == 0) {
            AESi_PxiSendFirst(0x13, 8, 1);
        }
        r = AESi_CalcMac(sign, data, length, data_02735AEC, CallbackForJpeg, &ev);
        if (r == 1) {
            r = OS_WaitEventEx(&ev, -1, 1, -1);
            if (r == 1) {
                MI_CpuCopy8(data_02735AEC, sign + 0xC, 0x10);
            }
        }
    } while (r == 4);
    if (data_02735AE4 == 0) {
        AESi_PxiSendFirst(0x13, 8, 0);
    }
    AESi_Unlock();
    return r;
}

int AESi_VerifySignForJpeg(u8 *sign, u32 data, u32 length)
{
    OSEventLike ev;
    int r;

    AESi_Lock();
    if (data_02735AE0 == 0) {
        AESi_InitRand();
    }
    OS_InitEvent(&ev);
    do {
        if (data_02735AE4 == 0) {
            AESi_PxiSendFirst(0x13, 8, 1);
        }
        r = AESi_CalcMac(sign, data, length, data_02735AEC, CallbackForJpeg, &ev);
        if (r == 1) {
            r = OS_WaitEventEx(&ev, -1, 1, -1);
            if (r == 1) {
                if (MI_CpuComp8(data_02735AEC, sign + 0xC, 0x10) != 0) {
                    r = 2;
                }
            }
        }
    } while (r == 4);
    if (data_02735AE4 == 0) {
        AESi_PxiSendFirst(0x13, 8, 0);
    }
    AESi_Unlock();
    return r;
}
