/*
 * function: func_02163E40
 * address:  0x02163E40
 * packet:   pkt_ov009_02163E40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    RC4 key schedule.  The permuter found the working form: the key index
 *           is a u8 incremented with `k = (k + 1) & 0xff` and wrapped by a statement
 *           `if (k >= len) k = 0;` placed after the swap-byte load `tmp = m[j]`, with
 *           `j = (k = 0)` as a chained initialiser and `tmp` a named local.
 *
 * sdk:      CPSi_rc4_init (libssl.TWL.HYB.a(arc4.o))
 *
 * symbols:
 *   (none)
 */

typedef struct {
    unsigned char x;
    unsigned char y;
    unsigned char m[256];
} CPSRc4Ctx;

void func_02163E40(CPSRc4Ctx *ctx, unsigned char *key, int len)
{
    unsigned char m_i;
    unsigned char *m = ctx->m;
    unsigned char j;
    unsigned char k;
    int i;
    unsigned char tmp;

    ctx->x = 0;
    ctx->y = 0;
    for (i = 0; i < 256; i++) {
        m[i] = i;
    }

    j = (k = 0);
    for (i = 0; i < 256; i++) {
        m_i = m[i];
        j = j + ((unsigned char)(m_i + key[k]));
        k = (k + 1) & 0xff;
        tmp = m[j];
        if (k >= len) {
            k = 0;
        }
        m[i] = tmp;
        m[j] = m_i;
    }
}
