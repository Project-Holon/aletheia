/*
 * function: func_021B7578
 * address:  0x021B7578
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guarded call to func_021B6868.
 *
 * symbols:
 *   func_021BE100  0x021BE100  thumb  ov172
 *   func_021B6868  0x021B6868  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021BE100(int x);
extern void func_021B6868(void *p);

void func_021B7578(int x, char *p)
{
    if (func_021BE100(x) == 1) {
        func_021B6868(*(void **)(p + 0xa4));
    }
}
