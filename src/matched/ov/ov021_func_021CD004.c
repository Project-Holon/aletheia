/*
 * function: PARTY_SELECT_LIST_CreateListWindow
 * address:  0x021CD004
 * packet:   pkt_ov021_021CD004
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Creates the +0xB4 handle of the work block once, from its +0xA4 object and +0xA8 entry.
 *
 * symbols:
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
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

struct Fx;
extern void *FIELD_MSGBG_CreateMsgWin(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);

void PARTY_SELECT_LIST_CreateListWindow(Work *w)
{
    if (w->fB4 == 0)
        w->fB4 = FIELD_MSGBG_CreateMsgWin(w->fA4, (u32)w->fA8, 1, 2, 0x1e, 6);
}
