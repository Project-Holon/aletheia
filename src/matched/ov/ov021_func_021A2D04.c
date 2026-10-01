/*
 * function: func_021A2D04
 * address:  0x021A2D04
 * packet:   pkt_ov021_021A2D04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0224  0x021A0224  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 pad0;
    u32 handle;
    u8 pad8[0x774];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2D04;

void func_021A0224(u32 h, int color, u32 value, int a, int b, int c);

void func_021A2D04(Obj021A2D04 *p)
{
    func_021A0224(p->handle, 0x7FDF, p->value, p->mode, p->mode, p->half);
}
