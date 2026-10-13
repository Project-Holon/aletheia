/*
 * function: NNSi_G2dGetCellTransferState
 * address:  0x02066878
 * packet:   pkt_02066754
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sCellTransferStateManager       0x02148B20  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Hdr02066878 {
    u32 w0;
    u32 w1;
    u32 base;
};

extern struct Hdr02066878 sCellTransferStateManager;

u8 *NNSi_G2dGetCellTransferState(u32 i)
{
    return (u8 *)sCellTransferStateManager.base + i * 0x30;
}
