/*
 * unit:     no
 * function: func_02042ED8
 * address:  0x02042ED8
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
 *
 * The text-screen fill of the three blitters func_02041300 dispatches to.
 * Like func_02042E34 it takes the slot's sub-object (slot + 8), so the
 * buffer pointer is at +0x00 and the screen-size code at +0x15, but the
 * buffer is a linear u16 screen here: the row base is `width * y`, not the
 * tiled func_02040EE0 mapping.
 *
 * The seventh argument is the write mode and decides what lands in the
 * entry: 0x11 writes the value as it stands, 0x10 keeps the existing palette
 * nibble and adds the value to it, and anything else folds the mode itself
 * into bits 12-15.  That last form is loop-invariant, so the compiler
 * materialises it once in the outer preheader (the `lsl #0x10 / lsr #0x10`
 * pair at +0x54 is the u16 narrowing of it); writing it as a local computed
 * before the nest would instead put it ahead of the y guard.
 *
 * Loop shape.  Both bounds are expressions in their own `for` condition,
 * `y < y0 + h` and `x < x0 + w`, over loop variables distinct from the two
 * origin parameters, and the row base is the subscript `entries[width * y +
 * x]` rather than a hoisted row pointer.  Every other arrangement is right
 * to within a register permutation and wrong by eleven bytes: binding either
 * bound to a local before the nest moves it ahead of the guard it belongs
 * behind and rotates the four scratch registers holding the bounds, the
 * width and the height.  The subscript form is also what puts the scaled x
 * in the base slot of the store, `strh r7, [sl, r1]` rather than
 * `[r3, sl]`.
 *
 * The mode arrives on the stack as a full word (`ldr`, not `ldrb`), so it is
 * `u32` here even though func_02041300 hands it a value that fits in a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042ED8.c \
 *       --func func_02042ED8 --addr 0x02042ED8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Screen {
    u16 *entries;
    u8   pad_04[0x11];
    u8   size_code;
};

extern void func_020422D4(u8 size_code, u8 *width, u8 *height);

void func_02042ED8(struct Screen *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u32 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = s->entries;
    if (entries == 0) {
        return;
    }

    func_020422D4(s->size_code, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            if (mode == 0x11) {
                entries[width * y + x] = value;
            } else if (mode == 0x10) {
                entries[width * y + x] =
                    value + (entries[width * y + x] & 0xf000);
            } else {
                entries[width * y + x] = (u16)(value + (mode << 12));
            }
        }
    }
}
