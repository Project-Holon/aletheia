/*
 * function: func_021F0CA0
 * address: 0x021F0CA0
 * packet: pkt_ov029_021F0CA0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum zero and f2,f4,f0,f6 logical store order recover the
 * original scheduling; the previous f2,f0,f4,f6 order differed at two stores.
 */
typedef struct { unsigned short f0, f2, f4, f6; unsigned char f8, f9; } Record;
typedef enum { Zero } ZeroValue;
void func_021F0CA0(Record *p, unsigned short a, unsigned char b, unsigned char c)
{
    ZeroValue z;
    z = Zero;
    p->f2 = b;
    p->f4 = z;
    p->f0 = b * 2;
    p->f6 = a;
    p->f8 = c;
    p->f9 = 1;
}
