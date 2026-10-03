/*
 * function: func_021CDF58
 * address:  0x021CDF58
 * packet:   pkt_ov093_021CDF58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021CE068  0x021CE068  thumb  ov093
 *   func_021CE08C  0x021CE08C  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_021CDFE4  0x021CDFE4  thumb  ov093
 *   func_021CE0E0  0x021CE0E0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021EAA00(void *o, u8 v);
extern void func_021CE068(u8 *p);
extern int func_021CE08C(u8 *p);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern u32 func_021CDFE4(u32 mode);
extern void func_021CE0E0(u8 *p);

int func_021CDF58(u8 *p, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(*(void **)(p + 0x54), p[0xc4]);
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021EAA5C(*(void **)(p + 0x54));
            *st = 2;
        } else if (func_021EAA34(*(void **)(p + 0x54), &buf) != 0) {
            p[0xc4] = buf;
            *st = 3;
        }
        break;
    case 2:
        p[0xc4] = func_021CDFE4(p[0xc4]);
        *st = *st + 1;
        break;
    case 3:
        func_021CE0E0(p);
        *st = *st + 1;
        break;
    case 4:
        *(u8 **)(p + 0xd8) = p + 0xc4;
        *(int *)(p + 0xdc) = 1;
        return 1;
    }
    return 0;
}
