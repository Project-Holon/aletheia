/*
 * function: FIELD_MSGBG_CreateMenuItems
 * address:  0x02190A20
 * packet:   pkt_02190A20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to BMP_MENUWORK_Create with no argument change.
 *
 * symbols:
 *   BMP_MENUWORK_Create  0x0201F81C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_MENUWORK_Create();

void FIELD_MSGBG_CreateMenuItems(void)
{
    BMP_MENUWORK_Create();
}
