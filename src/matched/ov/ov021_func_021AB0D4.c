/*
 * function: func_021AB0D4
 * address:  0x021AB0D4
 * packet:   pkt_ov021_021AB0D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs the lookup func_0218DAEC into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * symbols:
 *   func_0218DAEC  0x0218DAEC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern int func_0218DAEC(void *a, void *b, u32 *out);

int func_021AB0D4(void *a, void *b)
{
    u32 buf[4];

    if (func_0218DAEC(a, b, buf) == 1)
        return buf[2];
    return -1;
}
