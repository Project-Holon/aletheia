/*
 * unit:     no
 * function: func_020413B0
 * address:  0x020413B0
 * packet:   pkt_020409E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_020422D4  0x020422D4  arm
 *   func_02040EE0  0x02040EE0  arm
 *
 * Recolour a rectangle of the screen buffer of table slot `index`: for every
 * tile entry in the (x0, y0, w, h) box, replace the palette nibble in bits
 * 12..15 with `pal` and leave the low twelve bits alone.
 *
 * func_020422D4 turns the slot's screen-size code at +0x1d into the layer's
 * width and height in tiles, returned through two u8 out-parameters; the
 * later declaration gets the lower stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md), so `width` at
 * sp+9 has to be declared before `height` at sp+8.  The box is clipped
 * against those two: running off the right edge breaks the row, running off
 * the bottom returns outright.  func_02040EE0 is the same (x, y, size_code)
 * to linear-index helper src/matched/sub_02042FB0.c uses.
 *
 * Two loop-shape notes, each worth twelve bytes:
 *
 *  - The y bound must be only the `for` condition.  Writing the equivalent
 *    `if (y0 >= yEnd) return;` in front of the loop as well emits the
 *    predicated return twice: the compiler's own loop-rotation entry test
 *    already is that guard.
 *  - The x bound must stay an expression in the inner condition,
 *    `x < x0 + w`, not a local computed before the nest.  As an expression
 *    it is loop-invariant and gets hoisted into the outer loop's preheader,
 *    which is after the y guard; as a local it is computed before the guard,
 *    which is where the original does not have it.
 *
 * Both bounds are signed compares (bge/blt) because each is a sum of two u8
 * values and so has type int, while the two clip tests against width and
 * height are unsigned (bhs): there both sides are u8 and the front end knows
 * the range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020413B0.c \
 *       --func func_020413B0 --addr 0x020413B0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8   pad_00[8];
    u16 *screen;
    u8   pad_0c[0x11];
    u8   size_code;
    u8   pad_1e[0x0e];
};

extern struct Slot *g_02146A44;

extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern u16 func_02040EE0(int x, int y, u32 code);

void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal)
{
    u8   width;
    u8   height;
    u16 *screen;
    u8   x;
    int  yEnd;

    screen = g_02146A44[index].screen;
    if (screen == 0) {
        return;
    }

    func_020422D4(g_02146A44[index].size_code, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }
            i = func_02040EE0(x, y0, g_02146A44[index].size_code);
            screen[i] = (u16)((screen[i] & 0xfff) | (pal << 12));
        }
    }
}
