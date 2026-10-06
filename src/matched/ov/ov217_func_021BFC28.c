/*
 * function: func_021BFC28
 * address:  0x021BFC28
 * packet:   pkt_ov217_021BFC28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C10D8 0x021C10D8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021C10D8(void *a0);
void func_021BFC28(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C10D8((void *)(*(u32 *)(p + i * 4 + 0x2bc)));
        func_021C10D8((void *)(*(u32 *)(p + i * 4 + 0x2c4)));
    }
}
