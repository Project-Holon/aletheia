/*
 * function: FIELD_MSGBG_DeleteSubMsgWin
 * address:  0x0219196C
 * packet:   pkt_0219196C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FIELD_MSGBG_RemoveSubMsgWin  0x021931C4  thumb  ov021
 *   FIELD_MSGBG_FreeSubMsgWin  0x0219194C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct E;
extern struct E *FIELD_MSGBG_RemoveSubMsgWin(u8 *p, u32 v);
extern void FIELD_MSGBG_FreeSubMsgWin(void);

void FIELD_MSGBG_DeleteSubMsgWin(u32 a, u32 b)
{
    FIELD_MSGBG_RemoveSubMsgWin((u8 *)a, b);
    FIELD_MSGBG_FreeSubMsgWin();
}
