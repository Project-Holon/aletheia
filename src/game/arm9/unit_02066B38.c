/*
 * file:     unit_02066B38.c
 * unit:     no
 * function: sub_02066B38
 * address:  0x02066B38
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_02148B20  0x02148B20  data
 *   sub_020640B0   0x020640B0  arm
 *
 * Release one 0x30-byte cell of the bank whose array pointer lives at
 * +8 of the global at 0x02148B20: hand it to sub_020640B0, then clear the
 * nine words from +0xc to +0x2c.
 *
 * The element address is one `mla`, not a shift and an add, because 0x30 is
 * not a power of two: the size goes into r1, the array base into r2, and
 * the multiply-accumulate produces the cell pointer in one instruction.
 *
 * Nine separate `str` of the same register rather than a fill loop or a
 * call: the zero is materialised once in r0 after the call returns and
 * reused at all nine sites, which is what a run of plain field assignments
 * gives at this size.  The neighbouring cell fields at +0 to +8 are left
 * alone, so this is field-by-field clearing in the source, not a
 * `MI_CpuFill8` over a sub-range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02066B38.c \
 *       --func sub_02066B38 --addr 0x02066B38 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct CellTransferState {
    u8  pad_00[0x0c];
    u32 taskArg0;
    u32 taskArg1;
    u32 taskArg2;
    u32 taskArg3;
    u32 inUse;
    u32 changedMask;
    u32 requestMask;
    u32 baseAddr;
    u32 callbackArg;
};

struct CellTransferStateManager {
    u8           pad_00[8];
    struct CellTransferState *pStates;
};

extern struct CellTransferStateManager gUnk_02148B20;
typedef signed int     s32;
extern void sub_020640B0(s32 *tbl);

void sub_02066B38(u32 stateIdx)
{
    struct CellTransferState *state = &gUnk_02148B20.pStates[stateIdx];

    sub_020640B0((s32 *)state);
    state->taskArg0 = 0;
    state->taskArg1 = 0;
    state->taskArg2 = 0;
    state->taskArg3 = 0;
    state->inUse = 0;
    state->changedMask = 0;
    state->requestMask = 0;
    state->baseAddr = 0;
    state->callbackArg = 0;
}
