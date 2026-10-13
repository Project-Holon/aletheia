/*
 * function: FIELD_MSGBG_DeleteMenuItems
 * address:  0x02190A6C
 * packet:   pkt_02190A20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to BMP_MENUWORK_ReleaseItems with no argument change.
 *
 * symbols:
 *   BMP_MENUWORK_ReleaseItems  0x0201F8F4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot;
extern void BMP_MENUWORK_ReleaseItems(struct Slot *s);

void FIELD_MSGBG_DeleteMenuItems(u32 a)
{
    BMP_MENUWORK_ReleaseItems((struct Slot *)a);
}
