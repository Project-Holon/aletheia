/*
 * function: func_021D9DB0
 * address:  0x021D9DB0
 * packet:   pkt_ov093_021D9DB0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021D78AC   0x021D78AC  thumb ov093
 *   func_021D7D18   0x021D7D18  thumb ov093
 *   func_021D9E08   0x021D9E08  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

union USlot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

extern int func_021D775C(int a);
extern u32 func_021D78AC(u32 range);
extern union USlot func_021D7D18(int x);
extern void func_021D9E08(int a, int b, int c, union USlot d, int e);

void func_021D9DB0(int a, int b, int c)
{
    u32 r;
    int k;
    union USlot s;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    r = func_021D78AC(0x1e);
    if (r > 0x14) {
        k = 5;
    } else {
        k = 1;
        if (r <= 10)
            k = 2;
    }
    s = func_021D7D18(k);
    func_021D9E08(b, c, k, s, 0x1e);
}
