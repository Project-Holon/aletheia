/*
 * function: func_0218ADC8
 * address:  0x0218ADC8
 * packet:   pkt_ov021_0218ADC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a 0x1C byte rectangle record with func_02014110 from the object's
 * map value, an id and three words, and hands it to func_02012878.
 *
 * symbols:
 *   func_02014110  0x02014110  thumb
 *   func_02012878  0x02012878  thumb
 *   func_02188C9C  0x02188C9C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u16 func_02188C9C(u8 *p);
extern void func_02014110(void *p, u16 a, s16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
extern void func_02012878(void *p, void *rect);

void func_0218ADC8(u8 *p, int id, u32 *pos)
{
    u8 buf[0x1C];

    func_02014110(buf, func_02188C9C(*(u8 **)(p + 0x14)), id, 0, 0, pos[0], pos[1], pos[2]);
    func_02012878(*(void **)(p + 8), buf);
}
