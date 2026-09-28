/*
 * function: func_021D7D18
 * address:  0x021D7D18
 * packet:   pkt_ov093_021D7D18
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D7B8C  0x021D7B8C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

union Slot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};
extern u32 func_021D7B8C(u32 lo, u32 hi);
union Slot func_021D7D18(int x)
{
    union Slot s;
    s.raw = 0;
    switch (x) {
    case 1:
    case 3:
    case 4:
    case 5:
        s.s.kind = 1;
        break;
    case 2:
        s.s.kind = 2;
        s.s.lo = func_021D7B8C(2, 4);
        break;
    case 0:
    default:
        s.s.kind = 0;
        break;
    }
    return s;
}