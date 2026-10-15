/*
 * function: GTSNEGO_MSG_SetListEntry
 * address: 0x021D71B8
 * packet: pkt_ov120_021D71B8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02008554 0x02008554 thumb
 *   GTSNEGO_MSG_CreateListActor 0x021D7128 thumb ov120
 *   GTSNEGO_MSG_SetListActorPos 0x021D7190 thumb ov120
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void GTSNEGO_MSG_CreateListActor(u8 *, int, int);
extern void GTSNEGO_MSG_SetListActorPos(u8 *, int, int, int);
void GTSNEGO_MSG_SetListEntry(u8 *p, void *entry, int index)
{
    if (entry != 0) {
        GTSNEGO_MSG_CreateListActor(p, index, func_02008554((const struct Sub0200852CObj *)((int)entry)));
        GTSNEGO_MSG_SetListActorPos(p, index, 16, -48 * (1 - index));
    }
}
