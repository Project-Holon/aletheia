/*
 * function: func_021D59B4
 * address:  0x021D59B4
 * packet:   pkt_ov093_021D59B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Recursive MATCH unblocker attempt: blocker target of the parked
 * func_021E7388 and the callee of the matched func_021D7B74, left unmatched by
 * the prior 0x021D lane (size).  The getter is recovered: every relocation
 * resolves and the arm bodies match, but mwcc lays the arms out differently and
 * does not keep the switch index in r1 (`adds r1,r0` in the image), so the
 * pc-relative halfword table offsets and the prologue are off, 296 vs 292.
 * Source case order below matches the image arm order (8..12, then 1..7, then
 * 15/18/13/14/21/17/16/19/20); the residual is a front-end layout tie.
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

extern int func_021D587C(u8 *);
extern int func_021D58A8(u8 *);
extern int func_021D78E4(u16, int);
extern int func_021D62C4(u8 *, int);

int func_021D59B4(u8 *p)
{
    int v = func_021D587C(p);

    switch (v) {
    case 8:
        return func_021D78E4(func_021D58A8(p), *(u8 *)(p + 0xfc));
    case 9:
        return func_021D78E4(func_021D58A8(p), *(u8 *)(p + 0xfd));
    case 10:
        return func_021D78E4(func_021D58A8(p), *(u8 *)(p + 0xfe));
    case 11:
        return func_021D78E4(func_021D58A8(p), *(u8 *)(p + 0xff));
    case 12:
        return func_021D78E4(func_021D58A8(p), *(u8 *)(p + 0x100));
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
        return *(u16 *)(p + 0x13c);
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
