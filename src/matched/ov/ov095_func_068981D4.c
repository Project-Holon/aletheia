/*
 * unit: yes
 * function: HAND_FIELD_GetHandlersWonderRoom, HAND_FIELD_GetHandlersMagicRoom, HAND_FIELD_RoomMarkerNoop
 * address: 0x068981D4
 * packet: pkt_ov095_068981D4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHandFieldWonderRoomHandlers 0x0689D618 data a4
 *   gHandFieldMagicRoomHandlers 0x0689D608 data a4
 */
extern unsigned gHandFieldWonderRoomHandlers[];
extern unsigned gHandFieldMagicRoomHandlers[];
unsigned *HAND_FIELD_GetHandlersWonderRoom(unsigned *p)
{
    *p = 1;
    return gHandFieldWonderRoomHandlers;
}
unsigned *HAND_FIELD_GetHandlersMagicRoom(unsigned *p)
{
    *p = 1;
    return gHandFieldMagicRoomHandlers;
}
void HAND_FIELD_RoomMarkerNoop(void)
{
}
