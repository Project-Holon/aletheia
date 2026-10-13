/*
 * function: APP_TASKMENU_IsFinish
 * address:  0x020279E8
 * packet:   pkt_02027974
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 *
 * app_taskmenu.c's "does the menu need more than one page" predicate: the
 * per-page capacity is 16 divided by the entry height at +0x14, and the
 * answer is whether the entry count at +1 reaches it.
 *
 * The division is the unsigned runtime helper, so both operands are unsigned
 * and the comparison is `blo`
 * (docs/idioms/runtime-helper-reloc.md).  The 1-returning arm falls through
 * and the 0-returning arm is the branch target, which is the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `if` is
 * written `>=`, not `<`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020279E8.c \
 *       --func APP_TASKMENU_IsFinish --addr 0x020279E8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct TaskMenu {
    u8  pad00;
    u8  count;
    u8  pad02[0x12];
    u32 height;
};

u32 APP_TASKMENU_IsFinish(struct TaskMenu *m)
{
    if (m->count >= 16 / m->height) {
        return 1;
    }
    return 0;
}
