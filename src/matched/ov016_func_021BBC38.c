/*
 * function: MY_MD5Final
 * address:  0x021BBC38
 * packet:   pkt_ov016_021BBC8C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   Encode        0x021BC4D4  thumb
 *   MY_MD5Update  0x021BBBC0  thumb
 *   MD5_memset    0x021BC544  thumb
 *   PADDING       0x021DABD8  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol MY_MD5Final (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BBC38.c \
 *       --func MY_MD5Final --addr 0x021BBC38 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef unsigned long UINT4;
typedef unsigned char *POINTER;

typedef struct {
    UINT4         state[4];
    UINT4         count[2];
    unsigned char buffer[64];
} MY_MD5_CTX;

extern unsigned char PADDING[64];
extern void Encode(unsigned char *output, UINT4 *input, unsigned int len);
extern void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void MD5_memset(POINTER output, int value, unsigned int len);

void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context)
{
    unsigned char bits[8];
    unsigned int index;

    Encode(bits, context->count, 8);
    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    MY_MD5Update(context, PADDING, (index < 56) ? (56 - index) : (120 - index));
    MY_MD5Update(context, bits, 8);
    Encode(digest, context->state, 16);
    MD5_memset((POINTER)context, 0, sizeof(*context));
}
