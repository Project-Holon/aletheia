/*
 * file:     nns_g2d_cell_transfer.c
 * unit:     yes
 * function: NNSi_G2dGetCellTransferState, NNS_G2dSetCellTransferState, NNS_G2dInitCellTransferStateManager, NNS_G2dUpdateCellTransferStateManager, NNSi_G2dRequestCellTransferState, NNSi_G2dGetCellTransferStateIndex, NNSi_G2dResetCellTransferState
 * address:  0x02066878
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Initialise cell `idx` of the bank at 0x02148B20: clear it with
 * NNSi_G2dSrtcInitTable, set each of the three channels whose argument is not the
 * -1 sentinel through NNSi_G2dSrtcSetTable(rec, 0/1/2, v), then store the four
 * stacked words at +0x0c..+0x18.
 * FRONT END: a `../2.0/sp2` PIN row, the "kept constants" tell in its
 * sentinel form -- the same pin src/matched/NNSi_G2dGetCellTransferStateIndex.c takes in this
 * cluster and docs/notes/pkt_02066E30.c.txt records for 0x0206775C.  The
 * image materialises `mvn r0, #0` FRESH before each of the three guards and
 * compares register-to-register (0x020668B8, 0x020668D4, 0x020668F0).
 * dsi/1.1p1 -O4,p folds that: it emits `cmn rN, #1` for guards 2 and 3 and
 * even CSEs the first -1 off the 0x30 stride it already holds
 * (`sub r0, r4, #0x31`), giving 156 bytes against the image's 164.  Ten
 * sentinel spellings were measured under 1.1p1 and every one folds the same
 * way -- `0xffffffffu`, `~0u`, `(u32)(0 - 1)`, `-1` on signed parameters,
 * `(s32)0xffffffff`, `~v != 0`, a plain `u32 s = ~0u` per guard, a shared
 * one, and a `volatile u32 s` (196 bytes, worse) -- and a full permuter hill
 * (142 singles, --types) reaches 164 bytes only through junk type mutations
 * at 87 concrete out.  2.0/sp2 keeps all three rematerialisations and is
 * byte-exact.  The previous DIFF body in docs/notes/pkt_02066890.c.txt is
 * superseded by this file; its residue diagnosis was right, the fix was the
 * front end.
 * THE 0x30 STRIDE is one `mla`, not a shift and an add: 0x30 is not a power
 * of two, so `mov r4, #0x30` / `mla r4, idx, r4, base` is the whole address
 * computation, and it is the inlined form of the cluster's out-of-line
 * accessor NNSi_G2dGetCellTransferState (0x02066878).
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_G2dSetCellTransferState.c \
 *       --func NNS_G2dSetCellTransferState --addr 0x02066890 --cc ../2.0/sp2 --arm
 * Publish the record pool (callback, count, array) into the global bank at
 * 0x02148B20, then, for each of the n 0x30-byte records, run the per-record
 * routine NNSi_G2dSrtcInitTable on it and clear the nine words at +0x0C..+0x2C.
 * n == 0 is the predicated early return off the `movs` that loads it.
 * THE NINE STORES WRITE ZERO, NOT THE LOOP INDEX.  The loop's back edge is
 * `blo 0x02066954` (the argument move) and the `mov r4, r5` that feeds every
 * `str r4, [r7, #..]` sits at 0x02066950, *outside* that back edge, in the
 * preheader, where r5 is the counter's zero: the stored value is
 * loop-invariant and r4 is mwcc rematerialising the constant 0 off the
 * known-zero counter register.  Reading the copy as `v = i++` puts it back
 * inside the loop and costs 17 bytes; docs/notes/NNS_G2dInitCellTransferStateManager.c.txt (the
 * previous reading of this function, which called these stores "the record's
 * own loop index") is superseded by this file.
 * Two scheduling points that the bytes do pin:
 *   - `i = 0` is initialised BEFORE the three bank stores; moved after them
 *     the `mov r5, #0` lands after the `popeq` and 12 bytes differ.
 *   - the stores are written as plain `0` literals, which is also what makes
 *     the constant hoistable into r4.
 *   python tools/match.py one --src src/matched/NNS_G2dInitCellTransferStateManager.c \
 *       --func NNS_G2dInitCellTransferStateManager --addr 0x02066934 --cc 1.1p1 --arm
 * NitroSystem g2d cell-transfer manager, the per-frame update
 * (NNS_G2dUpdateCellTransferStateManager shape).  sCellTransferStateManager is the
 * manager's control block { transfer-request callback, state count, state
 * array }; each 0x30-byte state is NNSG2dCellTransferState: a three-word
 * VRAM location (NNSi_G2dSrtcGetTable = NNSi_G2dGetVramLocation), szDst,
 * pSrcNCGR +0x10, pSrcNCBR +0x14, szSrcData, bActive +0x1c, bDrawn +0x20,
 * bTransferRequested +0x24, srcOffset +0x28, szByte +0x2c.  For every
 * active state and every VRAM type (3D uses the NCBR, the two 2D types
 * the NCGR) whose request AND drawn bits are both set, it calls the
 * callback with (GFD type from tbl_020A1808, VRAM address, src + offset,
 * size) and clears the request bit on success; then clears bDrawn.
 * FRONT END: a ../2.0/sp2 pin row (sp2p2 gives the same bytes; 1.1p1 is
 * 236 bytes).  Four levers, each measured:
 *   - the VRAM-type loop variable is an ENUM (NNSG2dVRamType) bounded by
 *     its _MAX enumerator.  That is what keeps the image's dead
 *     `mov r7,#0 / cmp r7,#3 / bge` entry test; an int, short or char
 *     counter lets the front end fold it (the "dead compare" earlier
 *     notes chased through volatile counters).
 *   - the GFD-type table is NOT const: a const table load is sunk past the
 *     NNSi_G2dGetVramLocation call; the image loads it before the call
 *     and holds it in sb, which is the pressure that spills the outer i
 *     and the 0x30 offset to sp+4 / sp+0 (no volatile needed).
 *   - the request/drawn test is one inline returning `a && b`, which gives
 *     the shared zero (`mov fp, r7`) for the flag.
 *   - the type variable is declared at function scope beside i, which
 *     puts the state pointer in r8 and the type in r7.
 * Claim the first cell of the bank at 0x02148B20 whose +0x1c occupancy word
 * is not 1: set it to 1 and return the index, or return -1 when every cell
 * of the `count` is taken (and when the count is zero).
 * FRONT END: this is a `../2.0/sp2` PIN row, the "kept branches" tell.  The
 * claim block is five instructions (mov #0x30 / mla / mov #1 / str / bx lr)
 * and dsi/1.1p1 -O4,p IF-CONVERTS all five into movne / mlane / movne /
 * strne / bxne, which is 84 bytes against the image's 88.  2.0/sp2 keeps
 * the `beq` over the block and is byte-exact with the same source.  Under
 * 1.1p1 the residue is 4 bytes and 48 concrete out; a full permuter hill
 * (155 singles) and a 2000-compile anneal both fail to move it, and no loop
 * shape reaches it either (goto both polarities, for, while, a volatile
 * store target, a re-derived base pointer, an extra statement in the arm).
 * Only `u8 i` reaches 88 bytes under 1.1p1, and it pays an `and r0, #0xff`
 * the image does not have.  See docs/notes/pkt_02066AE0.c.txt.
 * TWO SOURCE LEVERS, both needed and both cheap to get wrong:
 *   - the entry test is `count > i` against the ZERO counter, not
 *     `count != 0`.  The image's `bls` at 0x02066AF0 is the loop's own
 *     unsigned pre-test hoisted; `!= 0` gives `beq` and is one byte wrong.
 *     This is the same lever src/matched/NNSi_G2dDrawCellToSurface3D.c needed.
 *   - the claim STORE is through the index, `sCellTransferStateManager.cells[i].used = 1`,
 *     while the SCAN is through the cursor `c`.  That is what makes the
 *     image spend `mov r1, #0x30` / `mla r1, r0, r1, ip` on a cell address
 *     it already has in r2: the accessor NNSi_G2dGetCellTransferState (0x02066878, the
 *     same `base + i * 0x30` shape) is inlined at the store and not at the
 *     load.  Storing through `c` drops both instructions.
 *   python3 tools/match.py one --src src/matched/NNSi_G2dGetCellTransferStateIndex.c \
 *       --func NNSi_G2dGetCellTransferStateIndex --addr 0x02066AE0 --cc ../2.0/sp2 --arm
 * Release one 0x30-byte cell of the bank whose array pointer lives at
 * +8 of the global at 0x02148B20: hand it to NNSi_G2dSrtcInitTable, then clear the
 * nine words from +0xc to +0x2c.
 * The element address is one `mla`, not a shift and an add, because 0x30 is
 * not a power of two: the size goes into r1, the array base into r2, and
 * the multiply-accumulate produces the cell pointer in one instruction.
 * Nine separate `str` of the same register rather than a fill loop or a
 * call: the zero is materialised once in r0 after the call returns and
 * reused at all nine sites, which is what a run of plain field assignments
 * gives at this size.  The neighbouring cell fields at +0 to +8 are left
 * alone, so this is field-by-field clearing in the source, not a
 * `MI_CpuFill8` over a sub-range.
 *   python tools/match.py one --src src/matched/NNSi_G2dResetCellTransferState.c \
 *       --func NNSi_G2dResetCellTransferState --addr 0x02066B38 --cc 1.1p1 --arm
 *
 * symbols:
 *   sCellTransferStateManager       0x02148B20  data
 *   NNSi_G2dSrtcInitTable   0x020640B0  arm
 *   NNSi_G2dSrtcSetTable   0x020640CC  arm
 *   tbl_020A1808    0x020A1808  data
 *   NNSi_G2dSrtcGetTable   0x020640D4  arm
 */
#include "../types.h"

#include "nns_g2d_cell_transfer.h"

typedef BOOL (*TransferFunc)(s32 type, u32 dstAddr, void *pSrc, u32 szByte);

typedef struct CellTransferStateManager {
    TransferFunc       pFuncTransfer;  /* +0x00 */
    u32                numState;       /* +0x04 */
    CellTransferState *pStateArray;    /* +0x08 */
} CellTransferStateManager;

#include "nns_g2d_srt_control.h"
CellTransferState *NNSi_G2dGetCellTransferState(u32 stateIdx);
void NNS_G2dSetCellTransferState(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void NNS_G2dInitCellTransferStateManager(CellTransferState *pStates, u32 numStates, TransferFunc pTransferFunc);
void NNS_G2dUpdateCellTransferStateManager(void);
CellTransferState *NNSi_G2dRequestCellTransferState(u32 stateIdx, u32 srcOffset, u32 szByte);
int NNSi_G2dGetCellTransferStateIndex(void);
void NNSi_G2dResetCellTransferState(u32 stateIdx);
extern CellTransferStateManager sCellTransferStateManager;
extern s32 tbl_020A1808[VRAM_TYPE_MAX];

CellTransferState *NNSi_G2dGetCellTransferState(u32 stateIdx)
{
    return &sCellTransferStateManager.pStateArray[stateIdx];
}

void NNS_G2dSetCellTransferState(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    CellTransferState *rec = &sCellTransferStateManager.pStateArray[idx];

    NNSi_G2dSrtcInitTable((s32 *)rec);
    if (a != 0xffffffffu) {
        NNSi_G2dSrtcSetTable((s32 *)rec, 0, a);
    }
    if (b != 0xffffffffu) {
        NNSi_G2dSrtcSetTable((s32 *)rec, 1, b);
    }
    if (c != 0xffffffffu) {
        NNSi_G2dSrtcSetTable((s32 *)rec, 2, c);
    }
    rec->szDst = d;
    rec->pSrcNCGR = (const void *)e;
    rec->pSrcNCBR = (const void *)f;
    rec->szSrcData = g;
}

void NNS_G2dInitCellTransferStateManager(CellTransferState *pStates, u32 numStates, TransferFunc pTransferFunc)
{
    u32 i = 0;

    sCellTransferStateManager.pFuncTransfer = pTransferFunc;
    sCellTransferStateManager.pStateArray   = pStates;
    sCellTransferStateManager.numState      = numStates;
    if (numStates == 0) return;
    do {
        NNSi_G2dSrtcInitTable((s32 *)pStates);
        pStates->szDst = 0; pStates->pSrcNCGR = 0; pStates->pSrcNCBR = 0;
        pStates->szSrcData = 0; pStates->bActive = 0; pStates->bDrawn = 0;
        pStates->bTransferRequested = 0; pStates->srcOffset = 0; pStates->szByte = 0;
        pStates++;
        i++;
    } while (i < numStates);
}

static inline BOOL ShouldTransfer_(const CellTransferState *s, VRamType t)
{
    return (BOOL)((s->bTransferRequested & (1 << t)) && (s->bDrawn & (1 << t)));
}

void NNS_G2dUpdateCellTransferStateManager(void)
{
    u32 i;
    VRamType t;

    for (i = 0; i < sCellTransferStateManager.numState; i++) {
        CellTransferState *s = &sCellTransferStateManager.pStateArray[i];
        if (s->bActive) {
            for (t = VRAM_TYPE_3DMAIN; t < VRAM_TYPE_MAX; t++) {
                if (ShouldTransfer_(s, t)) {
                    s32 gfdType = tbl_020A1808[t];
                    const void *src = (t == VRAM_TYPE_3DMAIN) ? s->pSrcNCBR : s->pSrcNCGR;
                    if ((*sCellTransferStateManager.pFuncTransfer)(gfdType,
                                                    NNSi_G2dSrtcGetTable((const s32 *)(&s->dstVramLocation), t),
                                                    (void *)((u32)src + s->srcOffset),
                                                    s->szByte))
                        s->bTransferRequested &= ~(1 << t);
                }
            }
            s->bDrawn = 0;
        }
    }
}

CellTransferState *NNSi_G2dRequestCellTransferState(u32 stateIdx, u32 srcOffset, u32 szByte)
{
    CellTransferState *state = NNSi_G2dGetCellTransferState(stateIdx);

    state->bTransferRequested = ~0;
    state->srcOffset = srcOffset;
    state->szByte = szByte;
    return state;
}

int NNSi_G2dGetCellTransferStateIndex(void)
{
    u32 i = 0;

    if (sCellTransferStateManager.numState > i) {
        CellTransferState *c = sCellTransferStateManager.pStateArray;
        do {
            if (c->bActive != 1) {
                sCellTransferStateManager.pStateArray[i].bActive = 1;
                return i;
            }
            i++;
            c++;
        } while (i < sCellTransferStateManager.numState);
    }
    return -1;
}

void NNSi_G2dResetCellTransferState(u32 stateIdx)
{
    CellTransferState *state = &sCellTransferStateManager.pStateArray[stateIdx];

    NNSi_G2dSrtcInitTable((s32 *)state);
    state->szDst = 0;
    state->pSrcNCGR = 0;
    state->pSrcNCBR = 0;
    state->szSrcData = 0;
    state->bActive = 0;
    state->bDrawn = 0;
    state->bTransferRequested = 0;
    state->srcOffset = 0;
    state->szByte = 0;
}
