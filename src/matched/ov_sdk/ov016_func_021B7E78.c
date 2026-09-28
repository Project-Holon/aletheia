/*
 * function: DecodeRC4
 * address:  0x021B7E78
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TANE            0x021DCDA8  data
 *   crc             0x021B7FD0  thumb
 *   AOSS_MALLOC     0x021B61B0  thumb
 *   AOSS_FREE       0x021B61C0  thumb
 *   aoss_set_error  0x021B6D74  thumb
 *   AOSS_Memcpy     0x021B8230  thumb
 *   RC4init         0x021B7F00  thumb
 *   RC4encrypt      0x021B7F64  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol DecodeRC4 (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7E78.c \
 *       --func DecodeRC4 --addr 0x021B7E78 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    unsigned int   x;
    unsigned int   y;
    unsigned char *state;
    unsigned int   SizeOfState;
} ArcfourContext;

extern unsigned char TANE[100];
extern unsigned char crc(unsigned char *buf, int len);
extern void *AOSS_MALLOC(int a);
extern void AOSS_FREE(void *a);
extern void aoss_set_error(unsigned int type);
extern void *AOSS_Memcpy(void *dest, void *src, int n);
extern void RC4init(ArcfourContext *ctx, unsigned char *key, unsigned int key_len, unsigned int size);
extern void RC4encrypt(ArcfourContext *ctx, unsigned char *dest, unsigned char *src, unsigned int len);

int DecodeRC4(unsigned char *srcData, unsigned char *DecodeData, int SizeOfData,
              unsigned char CRC, unsigned char *iv, unsigned char *key, int keylen)
{
    ArcfourContext ctx;
    unsigned char retCRC;

    ctx.state = AOSS_MALLOC(SizeOfData);
    if (ctx.state == 0) {
        aoss_set_error(2);
        return -1;
    }
    AOSS_Memcpy(TANE, iv, 2);
    AOSS_Memcpy(TANE + 2, key, keylen);
    RC4init(&ctx, TANE, keylen + 2, SizeOfData);
    RC4encrypt(&ctx, DecodeData, srcData, SizeOfData);
    retCRC = crc(DecodeData, SizeOfData);
    if (retCRC != CRC) {
        aoss_set_error(18);
        AOSS_FREE(ctx.state);
        return -1;
    }
    AOSS_FREE(ctx.state);
    return 0;
}
