/*
 * function: HAND_WAZA_FindPledgeCombo
 * address:  0x021E8384
 * packet:   pkt_ov093_021E8384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gPledgeComboTable  0x021F2CF0  data  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u16 a; u16 b; int v; } Ent;
extern Ent gPledgeComboTable[3];

int HAND_WAZA_FindPledgeCombo(u32 x, u32 y)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        if ((x == gPledgeComboTable[i].a && y == gPledgeComboTable[i].b) ||
            (y == gPledgeComboTable[i].a && x == gPledgeComboTable[i].b))
            return gPledgeComboTable[i].v;
    }
    return 0;
}
