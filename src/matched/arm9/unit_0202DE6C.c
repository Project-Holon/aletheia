/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202DE6C
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202DE6C
 *
 * symbols:
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *
 * Turns a pair of grid coordinates into a pair of pixel coordinates and
 * writes them through the fifth argument, which arrives on the stack: the
 * prologue pushes six registers and then reads `[sp, #0x18]`, which is
 * the first stack slot above them.
 *
 * Both scale factors are `* 8` on the result of an ARM helper, and in
 * both statements the helper's result sits on the right of the `+`, which
 * is where this compiler puts a call result written inline
 * (docs/idioms/commutative-operand-order-names-the-temporary.md); binding
 * either to a local moves it to the left and reallocates the function.
 *
 * Matched as a one-function unit because the two bytes of `00 00` at
 * 0x0202DE9A are the linker's inter-section fill before 0x0202DE9C.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202DE6C.c \
 *       --addr 0x0202DE6C --thumb
 */

typedef unsigned int u32;

struct Pos0202DE6C {
    u32 x;
    u32 y;
};

typedef unsigned char  u8;
struct Descriptor;
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

void sub_0202DE6C(u32 a, u32 b, u32 c, const struct Pos0202DE6C *base,
                  struct Pos0202DE6C *out)
{
    out->x = base->x + (b + BMP_WIN_GetPosX((struct Descriptor *)a) * 8);
    out->y = base->y + ((c << 4) + BMP_WIN_GetPosY((struct Descriptor *)a) * 8);
}
