/*
 * unit:     no
 * function: func_02042E34
 * address:  0x02042E34
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020422D4  0x020422D4  arm
 *   func_02040EE0  0x02040EE0  arm
 *
 * The 8bpp-screen fill of the three blitters func_02041300 dispatches to on
 * the bit-depth byte at +0x1c of the 0x2c-byte slot.  It takes the slot's
 * sub-object (slot + 8) rather than the slot index, so the buffer pointer is
 * at +0x00 and the screen-size code at +0x15, which are slot +0x08 and
 * +0x1d, the same two fields src/matched/func_020413B0.c reaches through the
 * table.
 *
 * Same clip-and-scan shape as func_020413B0, and the same two loop-shape
 * rules apply here: the y bound is only the `for` condition (the compiler's
 * loop-rotation entry test is the guard), and the x bound stays the
 * expression `x < x0 + w` so that it is hoisted into the outer preheader,
 * after the y guard rather than before it.  Both bounds are signed compares
 * (a sum of two u8 has type int); both clip tests against width and height
 * are unsigned, because there both sides are u8.
 *
 * The screen-size code is re-read from the object on every store, since the
 * store through the buffer pointer may alias it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042E34.c \
 *       --func func_02042E34 --addr 0x02042E34 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Surface {
    u8 *pixels;
    u8  pad_04[0x11];
    u8  size_code;
};

typedef unsigned short u16;
extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern u16 func_02040EE0(int x, int y, u32 code);

void func_02042E34(struct Surface *s, u8 value, u8 x0, u8 y0, u8 w, u8 h)
{
    u8  width;
    u8  height;
    u8 *pixels;
    u8  x;
    int yEnd;

    pixels = s->pixels;
    if (pixels == 0) {
        return;
    }

    func_020422D4(s->size_code, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            pixels[func_02040EE0(x, y0, s->size_code)] = value;
        }
    }
}
