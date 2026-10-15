/*
 * function: BSUBWAY_SCR_GetNpcEntryInfo
 * address:  0x021CBBD0
 * packet:   pkt_ov021_021CBBD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the three halfwords of table entry idx, or the empty triple (0, 0, 4) (unlabelled start).
 *
 * symbols:
 *   data_021DAEBC  0x021DAEBC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xa];
    u16 fa;
    u16 fc;
    u16 fe;
} Entry;

extern const Entry data_021DAEBC[];

void BSUBWAY_SCR_GetNpcEntryInfo(u8 *p, u32 idx, u16 *a, u16 *b, u16 *c)
{
    const Entry *e = &data_021DAEBC[idx];

    if (p[9] == 4) {
        *a = 0;
        *b = 0;
        *c = 4;
        return;
    }
    if (e->fe == 0) {
        *a = 0;
        *b = 0;
        *c = 4;
        return;
    }
    *a = e->fa;
    *b = e->fc;
    *c = e->fe;
}
