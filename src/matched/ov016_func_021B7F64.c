/*
 * function: RC4encrypt
 * address:  0x021B7F64
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   arcfour_byte  0x021B7F90  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol RC4encrypt (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7F64.c \
 *       --func RC4encrypt --addr 0x021B7F64 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    unsigned int   x;
    unsigned int   y;
    unsigned char *state;
    unsigned int   SizeOfState;
} ArcfourContext;

extern unsigned int arcfour_byte(ArcfourContext *ctx);

void RC4encrypt(ArcfourContext *ctx, unsigned char *dest, unsigned char *src, unsigned int len)
{
    unsigned int i;
    unsigned char state;

    for (i = 0; i < len; i++) {
        state = arcfour_byte(ctx);
        dest[i] = src[i] ^ state;
    }
}
