/*
 * file:     unit_02066878.c
 * function: func_02066878
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
 *   g_02148B20       0x02148B20  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct CellTransferStateManager {
    void *pTransferFunc;
    u32 numStates;
    u32 pStates;
};

extern struct CellTransferStateManager g_02148B20;

u8 *func_02066878(u32 stateIdx)
{
    return (u8 *)g_02148B20.pStates + stateIdx * 0x30;
}
