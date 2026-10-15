/*
 * function: FIELD_MSGBG_StoreSubMsgWin
 * address:  0x0219319C
 * packet:   pkt_ov021_0219319C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

int FIELD_MSGBG_StoreSubMsgWin(u8 *p, u32 v)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((u32 *)(p + 0xA0))[i] == 0) {
            ((u32 *)(p + 0xA0))[i] = v;
            return i;
        }
    }
    return i;
}
