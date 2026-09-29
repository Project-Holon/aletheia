/*
 * function: func_021CE0F8
 * address:  0x021CE0F8
 * packet:   pkt_ov093_021CE0F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021B8588(void **p);
extern void func_021EAF18(u8 *o, u32 a, u32 b);
extern u8 func_021D5440(u8 *q);
extern void func_021EAF50(u8 *o, u32 v);
extern void func_021EAF78(u8 *o, u8 v);

void func_021CE0F8(u8 *p, u8 *q, u8 *o)
{
    if (func_021B8588(*(void ***)p) != 3) {
        func_021EAF18(o, 1, 0x45);
        func_021EAF50(o, func_021D5440(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18(o, 1, 0x46);
        func_021EAF50(o, p[0x1a6]);
        func_021EAF78(o, 0);
    }
}
