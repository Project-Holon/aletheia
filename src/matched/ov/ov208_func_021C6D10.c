/*
 * function: ov208_func_021C6D10
 * address:  0x021C6D10
 * packet:   pkt_ov208_021C6D10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C6E30  0x021C6E30  thumb
 *   ov208_func_021C6D6C  0x021C6D6C  thumb
 *   func_0204B404  0x0204B404  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208Cursor {
    u8  slot;
    u8  pad;
    s16 x;
    s16 y;
};

extern u16  ov208_func_021C6E30(void *a0, u8 *p, int a2, u16 skip, u16 stop);
extern void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

int ov208_func_021C6D10(void *a0, u8 *p, int a2)
{
    struct Ov208Cursor c;
    int moved;
    u16 i;

    moved = 0;
    if (W(0x698) != 0) {
        i = ov208_func_021C6E30(a0, p, a2, H(0x54e), H(0x550));
        ov208_func_021C6D6C((u16)(H(0x548) - 1), i, 0, &c.slot, 0);
        c.x = c.slot;
        c.y = 0x30;
        func_0204B404((struct Obj *)W(0x5e8), (const struct Vec2 *)(&c.x), 0);
        moved = 1;
    }
    return moved;
}
