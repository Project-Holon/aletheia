/*
 * function: func_0204B84C
 * address:  0x0204B84C
 * packet:   pkt_0204B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct {
    char pad[0x60];
    unsigned int f60;
} S;

void func_0204B84C(S *p, unsigned int v)
{
    p->f60 = (p->f60 & ~0x30000) | ((v & 3) << 16);
}
