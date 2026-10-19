/*
 * function: set_random
 * address:  0x02162128
 * packet:   pkt_ov009_02162128
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      set_random (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   CPS_SslAddRandomSeed  0x02162248  arm  ov009
 *   func_02163C9C  0x02163C9C  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   CPSi_sha1_result_prng  0x02163E10  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA648  0x021AA648  data
 *   gCpsSslRandCtx  0x021A82E4  data
 *   g_021AA650  0x021AA650  data
 */

typedef unsigned long long u64;

typedef struct {
    unsigned long state[5];
    unsigned long count[2];
    unsigned char buffer[64];
} CPSSha1Ctx;

typedef struct {
    u64 x;
    u64 a;
    u64 c;
} Rand32Ctx;

extern void CPS_SslAddRandomSeed(void *random_seed, unsigned long len);
extern void func_02163C9C(CPSSha1Ctx *ctx);
extern unsigned long OS_DisableInterrupts(void);
extern void func_02163CF0(CPSSha1Ctx *ctx, void *data0, int datalen);
extern void CPSi_sha1_result_prng(void *ctx, unsigned char *digest);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

extern unsigned char g_021AA648;
extern Rand32Ctx gCpsSslRandCtx;
extern unsigned char g_021AA650[20];

static void set_random(unsigned char *d, int len)
{
    unsigned long enabled;
    CPSSha1Ctx ctx;
    unsigned char x[20];
    int i;
    int j;
    int r;
    unsigned int carry;
    unsigned long tmp;

    if (g_021AA648 == 0) {
        gCpsSslRandCtx.x = gCpsSslRandCtx.a * gCpsSslRandCtx.x + gCpsSslRandCtx.c;
        tmp = (unsigned long)(gCpsSslRandCtx.x >> 32);
        CPS_SslAddRandomSeed(&tmp, 4);
    }
    r = 20;
    for (i = 0; i < len;) {
        if (r == 20) {
            func_02163C9C(&ctx);
            enabled = OS_DisableInterrupts();
            func_02163CF0(&ctx, g_021AA650, 20);
            CPSi_sha1_result_prng(&ctx, x);
            carry = 1;
            for (j = 19; j >= 0; j--) {
                tmp = g_021AA650[j] + x[j] + carry;
                g_021AA650[j] = (unsigned char)tmp;
                carry = tmp >> 8;
            }
            OS_RestoreInterrupts(enabled);
            r = 0;
        }
        {
            unsigned char b = x[r++];
            if (b != 0)
                d[i++] = b;
        }
    }
}
