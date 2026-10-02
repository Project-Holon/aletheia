/*
 * function: func_021C18C4
 * address:  0x021C18C4
 * packet:   pkt_ov217_021C18C4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

struct Ent {
    u8 pad0[8];
    u8 len;
    u8 start;
    u8 end;
    u8 pad1[9];
};

void func_021C18C4(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++) {
        ((struct Ent *)(p + 0x1C))[i].start = sum;
        ((struct Ent *)(p + 0x1C))[i].end = sum + ((struct Ent *)(p + 0x1C))[i].len - 1;
        sum += ((struct Ent *)(p + 0x1C))[i].len;
    }
}
