/*
 * function: func_021B79D4
 * address:  0x021B79D4
 * packet:   pkt_ov021_021B79D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8028  0x021B8028  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B8028(void *, void *);

void func_021B79D4(void **o, void *out)
{
    if (o[5] != 0) {
        func_021B8028(o[5], out);
    }
}
