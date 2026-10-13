/*
 * function: BTL_SERVER_FLOW_DemoteActionOfPoke
 * address: 0x021BD1B0
 * packet: pkt_ov093_021BD1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_FindActionByPokeId 0x021BCA08 thumb ov093
 *   BTL_SERVER_FLOW_MoveActionToEnd 0x021BCC50 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c; u8 d0, flag; u16 pad; } E;
extern E *BTL_SERVER_FLOW_FindActionByPokeId(void *, u8);
extern void BTL_SERVER_FLOW_MoveActionToEnd(void *, E *);
int BTL_SERVER_FLOW_DemoteActionOfPoke(void *p, u8 x)
{
    E *e = BTL_SERVER_FLOW_FindActionByPokeId(p, x);
    if (e && e->flag == 0) {
        BTL_SERVER_FLOW_MoveActionToEnd(p, e);
        return 1;
    }
    return 0;
}
