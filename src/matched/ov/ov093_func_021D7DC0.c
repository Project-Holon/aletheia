/*
 * function: func_021D7DC0
 * address:  0x021D7DC0
 * packet:   pkt_ov093_021D7DC0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021D7B8C  0x021D7B8C  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 v; } Word;

extern Word func_021D7D18(int x);
extern u8 func_021D5440(u8 *p);
extern Word func_021E899C(u32 a);
extern u32 func_021D7B8C(u32 lo, u32 hi);
extern Word func_021E8940(u8 a);
extern Word func_021E89C0(void);

void func_021D7DC0(int a, int b, Word *out)
{
    u8 y;

    if (a < 6) {
        *out = func_021D7D18(a);
        return;
    }
    out->v = 0;
    switch (a) {
    case 7:
        *out = func_021E899C(func_021D5440((u8 *)b));
        break;
    case 6:
        y = func_021D7B8C(2, 5);
        *out = func_021E8940(y);
        break;
    default:
        *out = func_021E89C0();
        break;
    }
}
