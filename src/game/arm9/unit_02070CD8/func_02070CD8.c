/*
 * function: func_02070CD8
 * address:  0x02070CD8
 * packet:   pkt_02070CD8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * G3D joint-scale handler, the fourth entry of the function table at
 * 0x020A8290 (table word 0x02070CD8 at 0x020A829C), seeded because no
 * call or prologue names it.  The simple sibling of
 * src/matched/arm9/func_02070DDC.c: when the scale-is-one flag (bit 2)
 * is set it marks the result with bit 0, otherwise it copies the three
 * scale words into the result; either way it then sets bits 3 and 4.
 * The copy is three field assignments (ldr/str pairs), not a struct
 * assignment, which would emit ldm/stm.  The command pointer in r2 is
 * part of the table signature and is not read.
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Owner02070CD8 {
    u32 flags;   /* 0x00 */
    s32 f04;
    s32 f08;
    s32 f0c;
};

void func_02070CD8(struct Owner02070CD8 *o, const s32 *src, const u8 *cmd, u32 f)
{
    (void)cmd;

    if (f & 4) {
        o->flags |= 1;
    } else {
        o->f04 = src[0];
        o->f08 = src[1];
        o->f0c = src[2];
    }

    o->flags |= 0x18;
}
