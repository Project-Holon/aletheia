/*
 * function: CPS_SslAddRandomSeed
 * address:  0x02162248
 * packet:   pkt_ov009_02162248
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * callee of DWCi_Http_Yield (same region, open SDK).
 *
 * sdk:      CPS_SslAddRandomSeed (ssl.o)
 *
 * symbols:
 *   CPSi_sha1_init         0x02163c9c  arm
 *   OS_DisableInterrupts   0x02087988  arm
 *   CPSi_sha1_calc         0x02163cf0  arm
 *   CPSi_sha1_result       0x02163da8  arm
 *   OS_RestoreInterrupts   0x0208799c  arm
 *   pool                   0x021aa650  data  a4
 *   pool_initialized       0x021aa648  data
 */

typedef struct {
    unsigned long  state[5];
    unsigned long  count[2];
    unsigned char  buffer[64];
} CPSSha1Ctx;

extern unsigned char pool[20];
extern unsigned char pool_initialized;

extern void CPSi_sha1_init(CPSSha1Ctx *ctx);
extern unsigned long OS_DisableInterrupts(void);
extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

void CPS_SslAddRandomSeed(void *random_seed, unsigned long len)
{
    CPSSha1Ctx ctx;
    unsigned long enabled;

    CPSi_sha1_init(&ctx);
    enabled = OS_DisableInterrupts();
    CPSi_sha1_calc(&ctx, pool, 0x14);
    CPSi_sha1_calc(&ctx, random_seed, len);
    CPSi_sha1_result(&ctx, pool);
    OS_RestoreInterrupts(enabled);
    pool_initialized = 1;
}
