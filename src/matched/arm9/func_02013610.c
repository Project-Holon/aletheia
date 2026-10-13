/*
 * function: func_02013610
 * address:  0x02013610
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SETUP_SetupTrainerBase     0x020134F4  thumb
 *   BTL_SETUP_SetTrainer     0x02013284  thumb
 *
 * One of a family of four (0x02013610, 0x02013644, 0x02013678, 0x020136AC)
 * that differ only in the constant handed to BTL_SETUP_SetupTrainerBase as its third
 * argument - 0, 1, 2 and 3 - so this is the id-0 member of a table of
 * builders.  The fifth argument arrives on the stack (the `add r2, sp, #0x20`
 * / `ldrh` pair), which is why the prologue pushes six registers and then
 * takes eight more bytes.
 *
 * The same object goes to both calls; the second call's fourth argument is
 * the object plus 0x28 (the tail of the two stack arguments it forwards).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013610.c \
 *       --func func_02013610 --addr 0x02013610 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BTL_SETUP_SetupTrainerBase(u8 *p, u32 a, u32 id, u32 c, u16 d);
extern void BTL_SETUP_SetTrainer(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h);

void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    BTL_SETUP_SetupTrainerBase(p, a, 0, b, d);
    BTL_SETUP_SetTrainer(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}
