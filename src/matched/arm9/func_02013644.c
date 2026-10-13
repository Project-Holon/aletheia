/*
 * function: func_02013644
 * address:  0x02013644
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
 * Member 1 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * BTL_SETUP_SetupTrainerBase (1 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013644.c \
 *       --func func_02013644 --addr 0x02013644 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BTL_SETUP_SetupTrainerBase(u8 *p, u32 a, u32 id, u32 c, u16 d);
extern void BTL_SETUP_SetTrainer(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h);

void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    BTL_SETUP_SetupTrainerBase(p, a, 1, b, d);
    BTL_SETUP_SetTrainer(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}
