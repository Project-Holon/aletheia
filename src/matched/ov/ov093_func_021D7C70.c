/*
 * function: func_021D7C70
 * address:  0x021D7C70
 * packet:   pkt_ov093_021D7C70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021D7B8C  0x021D7B8C  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021E89F8  0x021E89F8  thumb  ov093
 *   func_021E8A28  0x021E8A28  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 v; } Word;
struct Sel { u16 kind : 4; u16 lo : 6; u16 hi : 6; };

extern u8 func_021D5440(int m);
extern Word func_021E899C(u32 a);
extern u32 func_021D7B8C(u32 lo, u32 hi);
extern Word func_021E8940(u8 a);
extern Word func_021E89F8(u8 a, u32 b);
extern Word func_021E8A28(u32 a, u8 b);

void func_021D7C70(struct Sel s, int m, Word *out)
{
    u8 x;
    u8 y;

    switch (s.kind) {
    case 3:
        *out = func_021E899C(func_021D5440(m));
        break;
    case 2:
        y = func_021D7B8C(s.lo, s.hi);
        *out = func_021E8940(y);
        break;
    case 1:
        *out = func_021E89F8(s.hi, s.lo);
        break;
    case 4:
        x = func_021D5440(m);
        y = func_021D7B8C(s.lo, s.hi);
        *out = func_021E8A28(x, y);
        break;
    case 0:
    default:
        break;
    }
}
