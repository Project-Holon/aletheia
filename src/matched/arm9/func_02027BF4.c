/*
 * function: APP_TASKMENU_UpdateCursorColorBlend
 * address:  0x02027BF4
 * packet:   pkt_02027BF4
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   tbl_020A1B38   0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask   0x02061CA4  arm
 *
 * Sibling of APP_TASKMENU_UpdateCursorColor: advance the u16 phase by 0x400 (wrapping at
 * 0x10000), take the sine-table value tbl_020A1B38[2*(phase>>4)+1], and
 * lerp channel by channel between two BGR555 colours c0 and c1 (the fifth
 * and sixth, stack, arguments); write the packed colour to *out and hand
 * it to NNS_GfdRegisterNewVramTransferTask with 0xf (mode <= 3) or 0x1f.
 *
 * Closed in wave 12.  The 59-byte residue the earlier note read as
 * scheduling of the six-way colour unpack was the third parameter's type:
 * `mode` is a u16.  Nothing in the instruction stream shows the width
 * (the parameter is homed with a plain str either way), but the narrower
 * type changes the order the scheduler emits the unpack prologue in,
 * which is exactly where all 59 bytes sat.  The
 * permuter found it inside an 11-mutation anneal result; `type:p(mode)` is
 * the only one of the eleven that matters.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s16 tbl_020A1B38[];
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);

void APP_TASKMENU_UpdateCursorColorBlend(u16 *phase, u16 *out, u16 mode, u32 slot,
                   u16 c0, u16 c1)
{
    s32 s;
    u8 r0c, g0c, b0c;
    u8 r1c, g1c, b1c;
    u8 r, g, b;

    r0c = (u8)(c0 & 0x1f);
    g0c = (u8)((c0 & (0x1f << 5)) >> 5);
    b0c = (u8)((c0 & (0x1f << 10)) >> 10);
    r1c = (u8)(c1 & 0x1f);
    g1c = (u8)((c1 & (0x1f << 5)) >> 5);
    b1c = (u8)((c1 & (0x1f << 10)) >> 10);

    if (*phase + 0x400 >= 0x10000) {
        *phase = (u16)(*phase - 0xfc00);
    } else {
        *phase = (u16)(*phase + 0x400);
    }

    s = (s16)((tbl_020A1B38[2 * (*phase >> 4) + 1] + 0x1000) / 2);

    b = (u8)(b0c + ((s * (b1c - b0c)) >> 12));
    r = (u8)(r0c + ((s * (r1c - r0c)) >> 12));
    g = (u8)(g0c + ((s * (g1c - g0c)) >> 12));

    *out = (u16)(r | (g << 5) | (b << 10));

    if (mode <= 3) {
        NNS_GfdRegisterNewVramTransferTask((void *)0xf, slot * 32 + 0xc, (u32)out, 2);
    } else {
        NNS_GfdRegisterNewVramTransferTask((void *)0x1f, slot * 32 + 0xc, (u32)out, 2);
    }
}
