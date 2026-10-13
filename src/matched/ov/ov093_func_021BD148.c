/*
 * function: BTL_SERVER_FLOW_PromoteActionOfPoke
 * address: 0x021BD148
 * packet: pkt_ov093_021BD148
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 0x021BD16E are alignment padding.
 * symbols:
 *   BTL_SERVER_FLOW_FindActionByPokeId 0x021BCA08 thumb ov093
 *   BTL_SERVER_FLOW_MoveActionForward 0x021BCB98 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c; u8 d0, flag; u16 pad; } E;
extern E *BTL_SERVER_FLOW_FindActionByPokeId(void *, u8);
extern int BTL_SERVER_FLOW_MoveActionForward(void *, E *, int);
int BTL_SERVER_FLOW_PromoteActionOfPoke(void *p, u8 x)
{
    E *e = BTL_SERVER_FLOW_FindActionByPokeId(p, x);
    if (e && e->flag == 0) {
        if (BTL_SERVER_FLOW_MoveActionForward(p, e, 0) >= 0) return 1;
    }
    return 0;
}
