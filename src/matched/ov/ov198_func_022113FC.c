/*
 * function: B_PLIST_MAIN_MoveActorByFlag
 * address: 0x022113FC
 * packet: pkt_ov198_022113FC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: delta is word-wide at this call; the callee's short extern inserts lsls/asrs absent from 0x02211418.
 * symbols:
 *   B_PLIST_MAIN_ShiftActors 0x0220F22C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void B_PLIST_MAIN_ShiftActors(u8 *, int, int);
void B_PLIST_MAIN_MoveActorByFlag(u8 *p, int a, int b)
{
    int delta = 1;
    if (a & delta) {
        if (b == 0) delta = 8;
        else delta = -8;
    } else {
        delta = -8;
        if (b != 0) delta = 8;
    }
    B_PLIST_MAIN_ShiftActors(p, a, delta);
}
