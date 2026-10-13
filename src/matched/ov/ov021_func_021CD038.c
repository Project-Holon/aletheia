/*
 * function: PARTY_SELECT_LIST_DeleteListWindow
 * address:  0x021CD038
 * packet:   pkt_ov021_021CD038
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +0xB4 handle of the work block if it is set and clears it.
 *
 * symbols:
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0xa4];
    void *fA4;
    void *fA8;
    u8 padAC[4];
    void *fB0;
    void *fB4;
} Work;

extern int FIELD_MSGBG_DeleteMsgWin(void *a);

void PARTY_SELECT_LIST_DeleteListWindow(Work *w)
{
    if (w->fB4 != 0) {
        FIELD_MSGBG_DeleteMsgWin((void *)w->fB4);
        w->fB4 = 0;
    }
}
