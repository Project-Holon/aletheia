/*
 * function: func_021D59B4
 * address:  0x021D59B4
 * packet:   pkt_ov093_021D59B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the switch value stays in r1 and is the hidden second argument of
 * func_021D58A8; case 17 falls through into case 16.
 *
 * symbols:
 *   func_021D587C  0x021D587C  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D78E4  0x021D78E4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern int func_021D587C(void *p, int k);
extern int func_021D58A8(u8 *, int);
extern unsigned short func_021D78E4(unsigned short a, int i);
extern int func_021D62C4(u8 *, int);

int func_021D59B4(u8 *p, int k)
{
    int v = func_021D587C(p, k);

    switch (v) {
    case 8:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)(p + 0xfc));
    case 9:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)(p + 0xfd));
    case 10:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)(p + 0xfe));
    case 11:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)(p + 0xff));
    case 12:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)(p + 0x100));
    case 1:
        return *(s8 *)(p + 0xfc);
    case 2:
        return *(s8 *)(p + 0xfd);
    case 3:
        return *(s8 *)(p + 0xfe);
    case 4:
        return *(s8 *)(p + 0xff);
    case 5:
        return *(s8 *)(p + 0x100);
    case 6:
        return *(s8 *)(p + 0x101);
    case 7:
        return *(s8 *)(p + 0x102);
    case 15:
        return *(u8 *)(p + 0x18);
    case 18:
        return *(u8 *)(p + 0xfa);
    case 13:
        return *(u16 *)(p + 0x10);
    case 14:
        return *(u16 *)(p + 0xe);
    case 21:
        return *(u8 *)(p + 0x1a);
    case 17:
        if (func_021D62C4(p, 0x10) != 0)
            return 0;
    case 16:
        return *(u16 *)(p + 0x13c);
    case 19:
        return *(u8 *)(p + 0x141);
    case 20:
        return *(u32 *)(p + 8);
    case 0:
        break;
    }
    return 0;
}
