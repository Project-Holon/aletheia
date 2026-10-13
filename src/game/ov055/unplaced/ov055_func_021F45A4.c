/*
 * function: CROWD_CloseChatterSlot
 * address:  0x021F45A4
 * packet:   pkt_ov055_021F45A4
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_DeleteSubMsgWin  0x0219196C  thumb  ov021
 *   CROWD_ClearChatterSlot  0x021F459C  thumb  ov055
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldMsgBg;

/* One speech window slot (8 bytes); same layout as CrowdChatterSlot in unit_021F39C0.c. */
typedef struct CrowdChatterSlot {
    u16 isOpen;                  /* 0x00 */
    u8 x;                        /* 0x02 window position in tiles */
    u8 y;                        /* 0x03 */
    u16 windowId;                /* 0x04 */
    s16 frames;                  /* 0x06 frames the window has been open */
} CrowdChatterSlot;

extern void FIELD_MSGBG_DeleteSubMsgWin(struct FieldMsgBg *msgBg, u32 windowId);
extern void CROWD_ClearChatterSlot(CrowdChatterSlot *slot);

/* Closes the speech window of an open slot and clears the slot. */
void CROWD_CloseChatterSlot(CrowdChatterSlot *slot, struct FieldMsgBg *msgBg)
{
    if (slot->isOpen != 0) {
        FIELD_MSGBG_DeleteSubMsgWin(msgBg, slot->windowId);
        CROWD_ClearChatterSlot(slot);
    }
}
