/*
 * file:     unit_02185854.c
 * unit:     yes
 * function: func_02185854, func_021858A8
 * address:  0x02185854
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A1A40  0x021A1A40 data
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
void func_02185854(unsigned char * digest, char * output);
void func_021858A8(unsigned char * input, unsigned int len, char * output);
extern char g_021A1A40[];


void func_02185854(unsigned char * digest, char * output)
{
    unsigned int i;

    for (i = 0; i < 16; i++)
    {
        output[i * 2] = g_021A1A40[digest[i] / 16];
        output[i * 2 + 1] = g_021A1A40[digest[i] % 16];
    }
    output[32] = 0;
}


/*
 * sdk:      GSMD5Digest (md5c)
 */
void func_021858A8(unsigned char * input, unsigned int len, char * output)
{
    struct GSMD5_CTX ctx;
    unsigned char digest[16];

    GSMD5Init(&ctx);
    GSMD5Update(&ctx, input, len);
    GSMD5Final(digest, &ctx);
    GSMD5Print(digest, output);
}
