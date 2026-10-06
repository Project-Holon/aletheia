/*
 * function: func_021CE170
 * address:  0x021CE170
 * packet:   pkt_ov093_021CE170
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CE068  0x021CE068  thumb  ov093
 *   func_021CE08C  0x021CE08C  thumb  ov093
 *   func_021CE150  0x021CE150  thumb  ov093
 *   func_021CE160  0x021CE160  thumb  ov093
 *   func_021CE308  0x021CE308  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021CE068(u8 *p);
extern int func_021CE08C(u8 *p);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CE160(u8 *p);
extern u32 func_021CE308(u8 *p);

u32 func_021CE170(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CE150(p, (void *)((u32)func_021CE308));
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        func_021CE08C(p);
        if (func_021CE160(p) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
