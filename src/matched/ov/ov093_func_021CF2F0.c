/*
 * function: func_021CF2F0
 * address:  0x021CF2F0
 * packet:   pkt_ov093_021CF2F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CF3F8  0x021CF3F8  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_021EA7FC  0x021EA7FC  thumb  ov093
 *   func_021EA814  0x021EA814  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021CE0E0  0x021CE0E0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021CF3F8(u8 *p);
extern u8 func_021B86C0(u8 **p);
extern void func_021EA7FC(u32 w);
extern u32 func_021EA814(u32 w);
extern u32 func_021F7EB4(void);
extern void func_021CE0E0(u8 *p);

u32 func_021CF2F0(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CF3F8(p);
        if (func_021B86C0(*(u8 ***)p) != 0) {
            p[0x1a9] = 1;
            func_021EA7FC(*(u32 *)(p + 0x54));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (func_021EA814(*(u32 *)(p + 0x54)) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021CE0E0(p);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
