/*
 * function: func_0202BA24
 * address:  0x0202BA24
 * packet:   pkt_0202B9F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0202BA24(u8 *p)
{
    u32 r6;
    int i;
    u8 *e;
    u32 mask;
    u8 *r7;

    i = 0;
    if (i >= 0x10) return;

    do {
        r6 = ((0x79u << 2) + 0x40);
        *(volatile u32 *)&r6 = r6;   /* defeat hoisting */

        e = p + i * 0x1c;
        mask = 1u;
        mask <<= i;

        *(u32 *)(e + 0x24) = i;
        *(u32 *)(e + 0x38) = 0x7fu;
        *(u16 *)(e + 0x3c) = (u16)mask;

        r7 = p + i * 4;
        *(u32 *)(r7 + (0x79u << 2)) = i;
        i++;
        *(u32 *)(r7 + r6) = i - 1;
    } while (i < 0x10);
}
