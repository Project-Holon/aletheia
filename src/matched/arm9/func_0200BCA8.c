/*
 * function: DAYCARE_IsSlotInUse
 * address:  0x0200BCA8
 * packet:   pkt_0200BCA8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 SODATEYA_CompactSlots
 * (wave A1, lane 13).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int active;
    u8 data[0xDC];
    u32 count;
} E;

int DAYCARE_IsSlotInUse(E *e, u32 i)
{
    if (i >= 2)
        return 0;
    return e[i].active;
}
