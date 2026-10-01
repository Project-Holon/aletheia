/*
 * function: func_0200E5F8
 * address:  0x0200E5F8
 * packet:   pkt_0200E5F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf: element idx of a five-entry array of 0x120 byte
 * records, the base itself when idx is out of range. Filed as the relocation
 * witness for ov021 func_021D0B58 (wave A1).
 */

typedef unsigned int u32;

char *func_0200E5F8(char *p, u32 idx)
{
    if (idx < 5) {
        p += idx * 0x120;
    }
    return p;
}
