/*
 * function: func_021BEA54
 * address:  0x021BEA54
 * packet:   pkt_ov217_021BEA54
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF7CC 0x021BF7CC thumb ov217
 *   func_021C11D0 0x021C11D0 thumb ov217
 *   func_021C26AC 0x021C26AC thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 *func_021BF76C(void *p);
extern u32 func_021BF7CC(void *p);
extern u8 func_021C11D0(u8 *p, u8 n);
extern u8 func_021C26AC(void *a, u8 b, u8 c);
void func_021BEA54(char *p)
{
    u8 *o = func_021BF76C(p);

    u32 k = func_021BF7CC(p);
    int v = func_021C11D0(o, 0);
    *(u8 *)(p + 0x2b9) = func_021C26AC(p + 0x38, (u8)k, (u8)v);
}
