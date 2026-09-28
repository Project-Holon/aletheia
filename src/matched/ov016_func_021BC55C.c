/*
 * function: MD5Encode
 * address:  0x021BC55C
 * packet:   pkt_ov016_021BBC8C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MY_MD5Init    0x021BBB98  thumb
 *   MY_MD5Update  0x021BBBC0  thumb
 *   MY_MD5Final   0x021BBC38  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol MD5Encode (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC55C.c \
 *       --func MD5Encode --addr 0x021BC55C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef unsigned long UINT4;

typedef struct {
    UINT4         state[4];
    UINT4         count[2];
    unsigned char buffer[64];
} MY_MD5_CTX;

extern void MY_MD5Init(MY_MD5_CTX *context);
extern void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context);

static void MD5Encode(unsigned char *digest, unsigned char *psrc, int srclen)
{
    MY_MD5_CTX context;

    MY_MD5Init(&context);
    MY_MD5Update(&context, psrc, srclen);
    MY_MD5Final(digest, &context);
}
