/*
 * function: BOX2_MAIN_CanPlaceInBox
 * address:  0x021DD718
 * packet:   pkt_ov170_021DD718
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/arm9/func_02019CF8.c (EXACT, Thumb forwarder to func_02019BBC).
 * Expected EXACT after the integrator's manifest refresh.
 *
 * symbols:
 *   func_02017E88 0x02017E88 thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02019D00 0x02019D00 thumb
 *   BOX2_MAIN_ChangeFormAndRegister 0x021DD6E8 thumb
 *
 * Re-derives the form of a species whose form follows its held item
 * (0x1ED by plate, 0x289 by drive, 0x1E7 by the item 0x70) and applies it;
 * returns 1 when the form changed.
 *
 * Blocker (MATCH): the call to 0x02019CF8 has no witness.  0x02019CF8 is an
 * 8-byte Thumb tail-call thunk (ldr r3, =0x02019BBD; bx r3) that the arm9
 * listing decodes as ARM and nothing else calls; seeding it as a Thumb
 * function start promotes this file to EXACT.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u16 func_02019CF8(u32 item);
extern u32 func_02019D00(u32 item);
extern void BOX2_MAIN_ChangeFormAndRegister(void **pp, void *a, u32 b);

int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon)
{
    u16 species = func_02017E88(mon, 5, 0);
    if (species == 0x1ED) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 form = func_02017E88(mon, 0x6F, 0);
        u16 want = func_02019CF8(item);
        if (form != want)
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x289) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 form = func_02017E88(mon, 0x6F, 0);
        u16 want = func_02019D00(item);
        if (form != want)
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x1E7) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 old = func_02017E88(mon, 0x6F, 0);
        u16 form = old;
        if (old == 0) {
            if (item == 0x70) {
                BOX2_MAIN_ChangeFormAndRegister(pp, mon, 1);
                form = 1;
            }
        } else if (item != 0x70) {
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, 0);
            form = 0;
        }
        if (old != form)
            return 1;
    }
    return 0;
}
