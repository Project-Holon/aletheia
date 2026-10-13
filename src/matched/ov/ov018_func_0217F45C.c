/*
 * function: EVENT_COMM_COMMON_DeleteListWindow
 * address:  0x0217F45C
 * packet:   pkt_ov018_0217F45C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 */

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef unsigned int   u32;
int FIELD_MSGBG_DeleteMsgWin(void *a);

void EVENT_COMM_COMMON_DeleteListWindow(Ov018Obj *p)
{
    if (p->f1C != 0) {
        FIELD_MSGBG_DeleteMsgWin((void *)p->f1C);
        p->f1C = 0;
    }
}
