/*
 * file:     unit_020432E4.c
 * function: sub_020432E4
 * address:  0x020432E4
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * The companion of sub_02043264: the same set / add / subtract triple, but
 * on the two affine center coordinates at +0x24 and +0x28, opcodes 9..14.
 * The table is rebased with a leading `sub r1, r1, #9`, so no empty low
 * arms are needed here.
 */

typedef unsigned short u16;
typedef unsigned int u32;

/* One background layer record (0x2C bytes).  Only the affine members past
 * the scroll and type fields are touched here. */
struct Bg {
    u32 head[6];     /* buffer, size, scroll: not used by this function */
    u16 rotation;    /* +0x18, angle */
    u16 rotationPad;
    u32 scaleX;      /* +0x1C, 0x1000 = 1.0 */
    u32 scaleY;      /* +0x20 */
    u32 centerX;     /* +0x24, rotation and scale center */
    u32 centerY;     /* +0x28 */
};

/* Opcode numbers; 0..8 belong to the rotation and scale versions. */
enum {
    BG_CENTER_X_SET = 9,
    BG_CENTER_X_ADD = 10,
    BG_CENTER_X_SUB = 11,
    BG_CENTER_Y_SET = 12,
    BG_CENTER_Y_ADD = 13,
    BG_CENTER_Y_SUB = 14
};

void sub_020432E4(struct Bg *bg, u32 opcode, u32 operand)
{
    switch (opcode) {
    case BG_CENTER_X_SET:
        bg->centerX = operand;
        break;
    case BG_CENTER_X_ADD:
        bg->centerX = bg->centerX + operand;
        break;
    case BG_CENTER_X_SUB:
        bg->centerX = bg->centerX - operand;
        break;
    case BG_CENTER_Y_SET:
        bg->centerY = operand;
        break;
    case BG_CENTER_Y_ADD:
        bg->centerY = bg->centerY + operand;
        break;
    case BG_CENTER_Y_SUB:
        bg->centerY = bg->centerY - operand;
        break;
    }
}
