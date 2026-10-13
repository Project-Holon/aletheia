/*
 * function: FIELD_MSGBG_RemoveSubMsgWin
 * address:  0x021931C4
 * packet:   pkt_ov021_021931C4
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

typedef struct E {
    u32 f00;
    u32 f04;
} E;

E *FIELD_MSGBG_RemoveSubMsgWin(u8 *p, u32 v)
{
    int i;
    E *e;

    for (i = 0; i < 8; i++) {
        if (((E **)(p + 0xA0))[i] != 0 && ((E **)(p + 0xA0))[i]->f04 == v) {
            e = ((E **)(p + 0xA0))[i];
            ((E **)(p + 0xA0))[i] = 0;
            return e;
        }
    }
    return 0;
}
