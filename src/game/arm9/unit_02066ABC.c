/*
 * file:     unit_02066ABC.c
 * unit:     no
 * function: func_02066ABC
 * address:  0x02066ABC
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
typedef unsigned char u8;

struct CellTransferState {
    u8  pad_00[0x24];
    int requestMask;
    int baseAddr;
    int callbackArg;
};

extern unsigned char *func_02066878(unsigned int i);

struct CellTransferState *func_02066ABC(int stateIdx, int baseAddr, int callbackArg)
{
    struct CellTransferState *state = (struct CellTransferState *)func_02066878(stateIdx);

    state->requestMask = ~0;
    state->baseAddr = baseAddr;
    state->callbackArg = callbackArg;
    return state;
}
