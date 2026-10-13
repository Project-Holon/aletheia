/*
 * function: AESi_InitRand
 * address:  0x02707570
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735AE0  0x02735AE0  data twl a2
 *   data_02735AE4  0x02735AE4  data twl a2
 *   data_02735AE8  0x02735AE8  data twl a2
 *   data_02735AEC  0x02735AEC  data twl a2
 *   data_02735B00  0x02735B00  data twl a2
 *   AESi_SeedRand  0x0270741C  arm
 */

typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned char u8;

typedef struct OSThread OSThread;
typedef struct {
    OSThread *head;
    OSThread *tail;
} OSThreadQueueLike;
struct OSEvent {
    OSThreadQueueLike queue;
    u32 flags;
};
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
extern void OS_InitTick(void);
extern void OS_GetLowEntropyData(u32 *out);
extern void MATH_CalcSHA1(void *digest, const void *data, u32 size);
extern u32 AESi_SeedRand(u32 *digest);

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
