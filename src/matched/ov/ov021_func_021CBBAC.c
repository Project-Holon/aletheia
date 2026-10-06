/*
 * function: func_021CBBAC
 * address:  0x021CBBAC
 * packet:   pkt_ov021_021CBBAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Whether entry idx of the 16-byte table at 0x021DAEBC is available (never for kind 4; unlabelled start).
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

u32 func_021CBBAC(u8 *p, u32 idx)
{
    const Entry *e = &data_021DAEBC[idx];

    if (p[9] == 4)
        return 0;
    if (e->fe != 0)
        return 1;
    return 0;
}
