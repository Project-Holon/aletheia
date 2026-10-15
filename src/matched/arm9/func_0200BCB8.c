/*
 * function: DAYCARE_GetInUseCount
 * address:  0x0200BCB8
 * packet:   pkt_0200BCB8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 SODATEYA_GetCompatibility
 * (wave A1, lane 13).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int active;
    u8 data[0xDC];
    u32 count;
} E;

int DAYCARE_GetInUseCount(E *e)
{
    int i;
    int n = 0;

    for (i = 0; i < 2; i++) {
        if (e[i].active == 1)
            n++;
    }
    return n;
}
