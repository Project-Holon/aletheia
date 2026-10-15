/*
 * function: STA_SLOT_PushRecord
 * address: 0x021FDA24
 * packet: pkt_ov132_021FDA24
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x188]; u32 flag; u32 slots[8]; } State;
void STA_SLOT_PushRecord(State *p, u32 a, u32 b, u32 c)
{
    u8 i;
    for (i = 0; i < 8; i++) {
        if (p->slots[i] == 0xffff) {
            p->slots[i] = (c << 16) + (a << 8) + b;
            p->flag = 1;
            return;
        }
    }
}
