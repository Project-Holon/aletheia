/*
 * function: GPOWER_ClearByPowerId
 * address:  0x02010F40
 * packet:   pkt_02010F18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the counter slot named by byte 0xA of entry idx in a 12-byte-entry table.
 *
 * symbols:
 *   GPOWER_ClearType  0x02010F50  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;

typedef struct {
    u8 pad0[0xa];
    u8 slot;
    u8 padB;
} Entry;

extern void GPOWER_ClearType(int idx);

void GPOWER_ClearByPowerId(int idx, Entry *tbl)
{
    GPOWER_ClearType(tbl[idx].slot);
}
