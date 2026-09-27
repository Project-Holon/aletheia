/*
 * function: func_0218DD14
 * address:  0x0218DD14
 * packet:   pkt_ov021_0218DD14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills a 0x14-byte descriptor from src: word0 from func_021A7404(src+0x68, a),
 * then src+0x64/+0x6c, the argument a, and b as a halfword at +0x10.
 * Callee of func_0218CEE4.  EXACT* (unlabelled follower 0x0218DD38).
 *
 * symbols:
 *   func_021A7404  0x021A7404  thumb  ov021
 */

extern int func_021A7404(int, int);

void func_0218DD14(int *dst, char *src, int a, int b)
{
    dst[0] = func_021A7404(*(int *)(src + 0x68), a);
    dst[1] = *(int *)(src + 0x64);
    dst[2] = *(int *)(src + 0x6c);
    dst[3] = a;
    *(unsigned short *)((char *)dst + 0x10) = b;
}
