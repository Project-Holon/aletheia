/*
 * function: func_021918DC
 * address:  0x021918DC
 * packet:   pkt_ov021_021918DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0219319C  0x0219319C  thumb  ov021
 *   func_020458F8  0x020458F8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045838  0x02045838  arm
 *   func_021917C4  0x021917C4  thumb  ov021
 *   d_021DDA50     0x021DDA50  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char d_021DDA50[];

extern u32 func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_0219319C(u16 *a, u32 *h);
extern u32 func_020458F8(u32 b);
extern u32 func_020457B0(u32 n, u32 heap);
extern void func_02045838(u32 w, u32 b);
extern void func_021917C4(u16 *a, u32 *h, u32 w, u32 t, u8 d, u8 e, u8 f, u8 g, u32 c);

/* d is u8: its caller (0x021B11B6) truncates r3, and the narrow type is what
 * pins its home store to the front of the prologue. */
void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g)
{
    u32 *h;
    u32 t;

    h = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0xE48);
    t = func_0219319C(a, h);
    h[0] = func_020457B0(func_020458F8(b) + 1, *a);
    func_02045838(h[0], b);
    func_021917C4(a, h, h[0], (u16)(t + 3), d, e, f, g, c);
}
