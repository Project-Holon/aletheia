/*
 * function: MB_SEQ_MoveCursorA
 * address: 0x021C76C0
 * packet: pkt_ov136_021C76C0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov136/mb_seq.c and filed here.
 *
 * symbols:
 *   MB_SEQ_MoveCursorToPosition 0x021C76D0 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
void MB_SEQ_MoveCursorA(u8 *p, u32 v);
void MB_SEQ_MoveCursorToPosition(u8 *p, u32 v);

void MB_SEQ_MoveCursorA(u8 *p, u32 v)
{
    MB_SEQ_MoveCursorToPosition(p, v);
}
