/*
 * function: BG_SYS_RotScale
 * address:  0x020423D4
 * packet:   pkt_02041F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_RotScaleMtx22   0x02051E74  arm
 *   BG_SYS_SetScrollRegs    0x02040860  arm
 *
 * One layer's affine setup: fill a scratch parameter block on the stack,
 * then push it into the layer through BG_SYS_SetScrollRegs with a zero transform.
 * The block is 0x10 bytes at sp+4 and the first call's fifth argument is
 * the word at sp+0, which is why the frame is `sub sp, sp, #0x14`: four
 * bytes of outgoing argument plus sixteen of local.
 *
 * The first call's third and fourth arguments are the same literal, so the
 * compiler materialises 0x1000 once in r2 and copies it to r3; the zero is
 * shared the same way and survives into the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_RotScale.c \
 *       --func BG_SYS_RotScale --addr 0x020423D4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Param {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

typedef unsigned char  u8;
struct Mtx22;
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void BG_SYS_SetScrollRegs(u32 layer, u32 a, u32 b, u32 c);

void BG_SYS_RotScale(u32 layer)
{
    struct Param p;

    BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&p), 0, (const void *)0x1000, (const void *)0x1000, 0);
    BG_SYS_SetScrollRegs(layer, (u32)(&p), 0, 0);
}
