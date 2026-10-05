/*
 * function: func_0202E82C
 * address:  0x0202E82C
 * packet:   pkt_0202E82C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 */

typedef unsigned char u8;
typedef struct S { u8 pad00[4]; int f04; } S;

void *func_0202E82C(S *p)
{
    if (p->f04 != 0)
        return (char *)p + 0x2C;
    return (char *)p + 0xC;
}
