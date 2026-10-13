/*
 * function: BTL_SETUP_SetupTrainerTag
 * address:  0x020136E0
 * packet:   pkt_020136E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SETUP_SetupTrainerBase  0x020134F4  thumb
 *   BTL_SETUP_SetTrainer  0x02013284  thumb
 *
 * The main variant of the three-slot setup (see BTL_SETUP_SetupTrainerMulti, the brief
 * one): the first call is the four-register form of the same writer with
 * count 1, then two calls into BTL_SETUP_SetTrainer that each carry the source's
 * own stack arguments - a word and the halfword at +4 of the argument
 * block - plus the two object sub-blocks at +0x28 and +0x30.  The last
 * store marks the object's +0x22 byte as the count of sub-blocks.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupTrainerTag.c \
 *       --func BTL_SETUP_SetupTrainerTag --addr 0x020136E0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj020136E0 {
    u8  pad00[0x22];
    u8  f22;            /* +0x22 */
};

extern void BTL_SETUP_SetupTrainerBase(u8 *p, u32 a1, u32 a2, u32 a3, u16 h);
extern void BTL_SETUP_SetTrainer(struct Obj020136E0 *o, u32 a1, u32 n, u8 *dst,
                          u32 v, u16 a5);

void BTL_SETUP_SetupTrainerTag(struct Obj020136E0 *o, u32 a1, u32 a2, u32 a3, u32 a4,
                   u16 a5)
{
    BTL_SETUP_SetupTrainerBase((u8 *)o, a1, 1, a2, a5);
    BTL_SETUP_SetTrainer(o, a1, 1, (u8 *)o + 0x28, a3, a5);
    BTL_SETUP_SetTrainer(o, a1, 3, (u8 *)o + 0x30, a4, a5);
    *((u8 *)o + 0x22) = 4;
}
