/*
 * function: func_021BF290
 * address:  0x021BF290
 * packet:   pkt_021BF290
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BF7AC 0x021BF7AC thumb
 *   func_021BF2DC 0x021BF2DC thumb
 */
#include "../include/Obj25327.h"

extern int func_021BF7AC(char *p, int v);
extern void func_021BF2DC(char *p, int a, int b, int c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);

void func_021BF290(int a, int b, int *s)
{
    unsigned char x = ((struct Obj25327 *)b)->f80;
    int r6 = s[2] * x;
    int r4 = s[1];
    int t = func_021BF7AC((char *)a, s[3]);

    func_021BF2DC((char *)a, s[0], r4 + r6, t, (unsigned char)s[4],
                  (unsigned char)s[5], (unsigned char)s[6], (unsigned char)s[7]);
}
