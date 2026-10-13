/*
 * file:     unit_02066878.c
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

struct CellTransferStateManager {
    void *pTransferFunc;
    u32 numStates;
    u32 pStates;
};

extern struct CellTransferStateManager sCellTransferStateManager;

u8 *NNSi_G2dGetCellTransferState(u32 stateIdx)
{
    return (u8 *)sCellTransferStateManager.pStates + stateIdx * 0x30;
}
