/*
 * function: func_021B9244
 * address:  0x021B9244
 * packet:   pkt_ov093_021B9244
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021D7FF8  0x021D7FF8  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Blk34;
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);
extern char *func_021B9AF8(char *p, int i);
extern u32 func_021D7FF8(u32 a, void *b);

u32 func_021B9244(char *p)
{
    u32 r;
    u32 m;
    u32 c;

    r = 0;
    if (((u32)*(u8 *)(p + 0x473) << 27 >> 31) == 0) {
        if (**(u32 **)p <= 1) {
            m = func_0200C274(func_02012F08(*(void **)(*(char **)p + 0x58)));
            c = func_021D7FF8(*(u8 *)(*(char **)p + 0x80), func_021B9AF8(p + 0x1b0, *(u8 *)(p + 0x46c)));
            if (c > m)
                c = m;
            r = c;
            *(u32 *)(p + 0x438) = r;
        }
        *(u8 *)(p + 0x473) |= 0x10;
    }
    return r;
}
