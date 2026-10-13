/*
 * file:     unit_02066ABC.c
 * unit:     no
 * function: NNSi_G2dRequestCellTransferState
 * address:  0x02066ABC
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dGetCellTransferState  0x02066878  arm
 */
typedef unsigned char u8;

struct CellTransferState {
    u8  pad_00[0x24];
    int requestMask;
    int baseAddr;
    int callbackArg;
};

extern unsigned char *NNSi_G2dGetCellTransferState(unsigned int i);

struct CellTransferState *NNSi_G2dRequestCellTransferState(int stateIdx, int baseAddr, int callbackArg)
{
    struct CellTransferState *state = (struct CellTransferState *)NNSi_G2dGetCellTransferState(stateIdx);

    state->requestMask = ~0;
    state->baseAddr = baseAddr;
    state->callbackArg = callbackArg;
    return state;
}
