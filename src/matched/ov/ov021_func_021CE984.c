/*
 * function: COMM_ENTRY_MENU_EraseMemberName
 * address:  0x021CE984
 * packet:   pkt_ov021_021CE984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_FillMsgWin  0x02190794  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Slot;
extern void FIELD_MSGBG_FillMsgWin(struct Slot **p, int x, int y, int w, int h);

void COMM_ENTRY_MENU_EraseMemberName(u32 *p, u32 n)
{
    if (p[3] != 0) {
        FIELD_MSGBG_FillMsgWin((struct Slot **)p[3], 0, n << 4, 0x90, 0x10);
    }
}
