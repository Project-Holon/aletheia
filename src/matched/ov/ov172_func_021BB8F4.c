/*
 * function: func_021BB8F4
 * address:  0x021BB8F4
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Maps the +4 state to an output code through the two ARM9 probes, 9/6/0xd.
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

extern u32 func_021BE0D0(void *p);
extern u32 func_021BDFE4(void *p);
extern u32 func_021B80E4(int unused, char *p);
extern u8 func_021BE054(void *p);

int func_021BB8F4(void *a0, int *out)
{
    if (func_021BE0D0(a0) == 1) {
        int v = func_021B80E4((int)a0, (char *)func_021BDFE4(a0));

        *out = (v == 5) ? 9 : 6;
        return 1;
    }
    if (func_021BE054(a0) <= 1) {
        *out = 0xd;
        return 1;
    }
    return 0;
}
