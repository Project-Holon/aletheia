/*
 * function: func_021B785C
 * address:  0x021B785C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Table lookup at g_021C6EB4, value shifted in the second arm.
 *
 * symbols:
 *   func_021BE05C  0x021BE05C  thumb  ov172
 *   func_021BE078  0x021BE078  thumb  ov172
 *   g_021C6EB4    0x021C6EB4  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 g_021C6EB4[];

u32 func_021B785C(void *p)
{
    u32 i = func_021BE05C(p);
    if (func_021BE078(p) == 0) {
        return g_021C6EB4[i];
    }
    return g_021C6EB4[i] >> 2;
}
