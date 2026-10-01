/*
 * function: func_021CE3D8
 * address:  0x021CE3D8
 * packet:   pkt_ov021_021CE3D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears the state byte of entry i of the four 0x2C-byte entries at +0x70.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 state;
    u8 pad1[0x2b];
} Entry;

typedef struct {
    u8 pad0[0x70];
    Entry ent[4];
} Mgr;

void func_021CE3D8(Mgr *m, int i)
{
    m->ent[i].state = 0;
}
