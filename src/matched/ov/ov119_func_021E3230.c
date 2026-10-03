/*
 * function: func_021E3230
 * address:  0x021E3230
 * packet:   pkt_021E3230
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E32C4  0x021E32C4  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_021E32C4(char *p);

void func_021E3230(void *p)
{
    if (*(u32 *)((char *)p + 0x109C) != 0xFFFFFFFF) {
        func_021E32C4(p);
        *(u32 *)((char *)p + 0x109C) = 0xFFFFFFFF;
    }
}
