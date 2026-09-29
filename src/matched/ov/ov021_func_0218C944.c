/*
 * function: func_0218C944
 * address:  0x0218C944
 * packet:   pkt_ov021_0218C944
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up a 10-byte-stride table row by key and reads column idx.
 *
 * symbols:
 *   func_0218C924  0x0218C924  thumb  ov021
 *   d_021D3D88     0x021D3D88  data   a2
 *   d_021D3D8A     0x021D3D8A  data   a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0218C924(void *p);
extern u8 d_021D3D88[];
extern u8 d_021D3D8A[];

int func_0218C944(void *p, u32 idx, u16 *out)
{
    u32 key;
    u32 j;

    if (p == 0)
        return 0;
    key = func_0218C924(p);
    *out = 0;
    if (idx >= 4)
        return 0;
    for (j = 0; j < 6; j++) {
        if (key == *(u16 *)(d_021D3D88 + j * 10)) {
            *out = *(u16 *)(d_021D3D8A + j * 10 + idx * 2);
            return 1;
        }
    }
    return 0;
}
