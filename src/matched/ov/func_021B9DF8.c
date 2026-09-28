/*
 * function: func_021B9DF8
 * address:  0x021B9DF8
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps the +4 state to an output code through the two ARM9 probes.
 *
 * symbols:
 *   func_021BE0D0  0x021BE0D0  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021B80E4  0x021B80E4  thumb  ov172
 *   func_021BE054  0x021BE054  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021BE0D0(void *p);
extern int func_021BDFE4(void *p);
extern int func_021B80E4(void *p, int v);
extern u32 func_021BE054(void *p);

int func_021B9DF8(void *p, int *out)
{
    if (func_021BE0D0(p) == 1) {
        int v = func_021B80E4(p, func_021BDFE4(p));

        *out = (v == 5) ? 0x10 : 0xd;
        return 1;
    }
    if (func_021BE054(p) <= 1) {
        *out = 0x14;
        return 1;
    }
    return 0;
}
