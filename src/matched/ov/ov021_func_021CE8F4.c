/*
 * function: func_021CE8F4
 * address:  0x021CE8F4
 * packet:   pkt_ov021_021CE8F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021CE984  0x021CE984  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   data_021DB470  0x021DB470  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef struct { u8 b[6]; } Mac;

typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_021CE984(u8 *p, int i);
extern void func_02082D44(void *src, void *dst, int n);
extern u8 data_021DB470[];

void func_021CE8F4(u8 *p, u8 *e, int i)
{
    if (func_0203EFC8(p + 0x55a + i * 6, data_021DB470, 6)) {
        func_021CE984(p, i);
        func_02082D44(data_021DB470, ((Mac *)(p + 0x55a))[i].b, 6);
    }
}
