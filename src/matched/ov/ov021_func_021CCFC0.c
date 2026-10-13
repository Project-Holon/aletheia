/*
 * function: PARTY_SELECT_LIST_CreateTextWindow
 * address:  0x021CCFC0
 * packet:   pkt_ov021_021CCFC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the +0xB0 handle of the work block from its +0xA4 object and +0xA8 entry.
 *
 * symbols:
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
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
struct Obj2;
extern struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(struct Fx *a, u32 b);

void PARTY_SELECT_LIST_CreateTextWindow(Work *w)
{
    w->fB0 = FIELD_MSGBG_CreateBottomSysWin(w->fA4, (u32)w->fA8);
}
