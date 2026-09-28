/*
 * function: func_021858A8
 * address:  0x021858A8
 * packet:   pkt_ov009_021858A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSMD5Digest (md5c)
 *
 * symbols:
 *   GSMD5Init    0x02184938 arm ov009
 *   GSMD5Update  0x0218497C arm ov009
 *   GSMD5Final   0x02184A34 arm ov009
 *   GSMD5Print   0x02185854 arm ov009
 */

struct GSMD5_CTX {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
};

extern void GSMD5Init(struct GSMD5_CTX * context);
extern void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);
extern void GSMD5Final(unsigned char * digest, struct GSMD5_CTX * context);
extern void GSMD5Print(unsigned char * digest, char * output);

void func_021858A8(unsigned char * input, unsigned int len, char * output)
{
    struct GSMD5_CTX ctx;
    unsigned char digest[16];

    GSMD5Init(&ctx);
    GSMD5Update(&ctx, input, len);
    GSMD5Final(digest, &ctx);
    GSMD5Print(digest, output);
}
