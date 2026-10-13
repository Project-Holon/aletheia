/*
 * function: INTRUDE_COMM_AddSessionMember
 * address: 0x021759C0
 * packet: pkt_ov011_021759C0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u8 mask conversion through SetBits inline preserves the original
 * field load before the truncation finishes; open-coded byte locals differ.
 * symbols:
 *   func_0203F4FC 0x0203F4FC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0203F4FC(void);
typedef struct {
    u8 pad0[0x190];
    u32 stamp;
    u8 pad194[9];
    u8 active;
    u8 pending;
} State;
static inline void SetBits(State *p, u8 bit)
{
    p->active |= bit;
    p->pending |= bit;
}
void INTRUDE_COMM_AddSessionMember(State *p, u8 index)
{
    if (p->active == 0) p->stamp = func_0203F4FC();
    SetBits(p, 1 << index);
}
