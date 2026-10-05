/*
 * function: func_021DCE60
 * address:  0x021DCE60
 * packet:   pkt_021DCE60
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   d_021E2EF8     0x021E2EF8  data
 *
 * Maps a code 0..14 to a class: 0 for code 0, 2 for codes 1 to 14; any other code asserts and yields 0.
 */

typedef unsigned long u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[];

u32 func_021DCE60(int a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 2;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    case 13:
        return 2;
    case 14:
        return 2;
    }
    func_02034714(d_021E2EF8, 0, d_021E2EF8);
    return 0;
}
