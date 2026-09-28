/*
 * function: sub_0201B970
 * address:  0x0201B970
 * packet:   pkt_0201B970
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   sub_0201C158   0x0201C158  thumb
 *
 * pokeparty.c.  Restore PP to one move slot: read the move (0x36 + slot),
 * its current PP (0x3A + slot) and its PP ups (0x3E + slot), ask
 * sub_0201C158 for the slot's maximum, and if the slot is short either fill
 * it (amount 0x7F) or add `amount` and clamp at the maximum.
 *
 * The last register copy (`adds r2, r4, #0` ahead of func_02017E40, the new
 * PP kept in r4 where the old one lived) is the compound assignment
 * `pp += (u8)amount`: the spelled-out `pp = (u8)(pp + (u8)amount)` starts a
 * new value that coalesces straight into the argument register (wave 15;
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-
 * the-cached-load.md is the same lever on a field).  sub_0201C158 returns a
 * u8, so `max` is u8 (wave 14).  The dead store `id = slot` is the image's
 * `str r0, [sp]` before the add.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201B970.c \
 *       --func sub_0201B970 --addr 0x0201B970 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u8   sub_0201C158(u32 move, u32 ppUp);

u32 sub_0201B970(void *mon, u32 slot, u32 amount)
{
    u32 move;
    u32 id;
    u8  pp;
    u32 ppUp;
    u8  max;

    move = (u16)func_02017E1C(mon, slot + 0x36, 0);
    if (move == 0) {
        return 0;
    }
    id = slot;
    id = slot + 0x3A;
    pp = (u8)func_02017E1C(mon, id, 0);
    ppUp = func_02017E1C(mon, slot + 0x3E, 0);
    max = sub_0201C158(move, (u8)ppUp);
    if (pp < max) {
        if (amount == 0x7F) {
            pp = max;
        } else {
            pp += (u8)amount;
            if (pp > max) {
                pp = max;
            }
        }
        func_02017E40(mon, id, pp);
        return 1;
    }
    return 0;
}
