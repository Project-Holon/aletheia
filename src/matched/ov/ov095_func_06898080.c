/*
 * unit:     yes
 * function: HAND_FIELD_RemoveFactor, HAND_FIELD_GetHandlersWeatherMarker, HAND_FIELD_WeatherMarkerNoop, HAND_FIELD_GetHandlersTrickRoom, HAND_FIELD_TrickRoomReverseSpeed, HAND_FIELD_GetHandlersGravity, HAND_FIELD_GravityBoostAccuracy
 * address:  0x06898080
 * packet:   pkt_ov095_06898080
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handed extent 0x06898070 (92 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D6F0C (ARM linker stub, not compilable); the seven functions after
 * it (0x06898080..0x068980CC) are this unit. Two of them (0x06898094,
 * 0x06898088) are entries of the {key, fn} table at 0x0689D630 that
 * HAND_FIELD_AddFactor walks.
 *
 * symbols:
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gHandFieldWeatherMarkerHandlers     0x0689D638  data   ov095  a4
 *   gHandFieldTrickRoomHandlers     0x0689D630  data   ov095  a4
 *   gHandFieldGravityHandlers     0x0689D640  data   ov095  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gHandFieldWeatherMarkerHandlers[];
extern u8 gHandFieldTrickRoomHandlers[];
extern u8 gHandFieldGravityHandlers[];
struct Node;
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_EVENT_MultiplyVar(int key, int m);

void HAND_FIELD_RemoveFactor(void *n)
{
    BTL_EVENT_RemoveFactor(n);
}

u8 *HAND_FIELD_GetHandlersWeatherMarker(u32 *p)
{
    *p = 1;
    return gHandFieldWeatherMarkerHandlers;
}

void HAND_FIELD_WeatherMarkerNoop(void)
{
}

u8 *HAND_FIELD_GetHandlersTrickRoom(u32 *p)
{
    *p = 1;
    return gHandFieldTrickRoomHandlers;
}

void HAND_FIELD_TrickRoomReverseSpeed(void)
{
    BTL_EVENT_OverwriteVar(0x4a, 1);
}

u8 *HAND_FIELD_GetHandlersGravity(u32 *p)
{
    *p = 2;
    return gHandFieldGravityHandlers;
}

void HAND_FIELD_GravityBoostAccuracy(void)
{
    BTL_EVENT_MultiplyVar(0x35, 0x1ab8);
}
