/*
 * unit:     no
 * function: func_02066998
 * address:  0x02066998
 * packet:   pkt_02066740
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sCellTransferStateManager      0x02148B20  data
 *   tbl_020A1808    0x020A1808  data
 *   NNSi_G2dSrtcGetTable   0x020640D4  arm
 *
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
 *
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
 */

typedef unsigned int u32;
typedef int          s32;
typedef int          BOOL;

typedef enum {
    VRAM_TYPE_3DMAIN = 0,
    VRAM_TYPE_2DMAIN,
    VRAM_TYPE_2DSUB,
    VRAM_TYPE_MAX
} VRamType;

typedef struct {
    u32 baseAddrOfVram[VRAM_TYPE_MAX];
} VRamLocation;

typedef struct {
    VRamLocation dstVramLocation;   /* +0x00 */
    u32          szDst;             /* +0x0c */
    const void  *pSrcNCGR;          /* +0x10 */
    const void  *pSrcNCBR;          /* +0x14 */
    u32          szSrcData;         /* +0x18 */
    BOOL         bActive;           /* +0x1c */
    u32          bDrawn;            /* +0x20 */
    u32          bTransferRequested;/* +0x24 */
    u32          srcOffset;         /* +0x28 */
    u32          szByte;            /* +0x2c */
} CellTransferState;

typedef BOOL (*TransferFunc)(s32 type, u32 dstAddr, void *pSrc, u32 szByte);

struct CellTransferManager {
    TransferFunc       pFuncTransfer;  /* +0x00 */
    u32                numState;       /* +0x04 */
    CellTransferState *pStateArray;    /* +0x08 */
};

extern struct CellTransferManager sCellTransferStateManager;
extern s32 tbl_020A1808[VRAM_TYPE_MAX];
extern s32 NNSi_G2dSrtcGetTable(const s32 *tbl, u32 i);

static inline BOOL ShouldTransfer_(const CellTransferState *s, VRamType t)
{
    return (BOOL)((s->bTransferRequested & (1 << t)) && (s->bDrawn & (1 << t)));
}

void func_02066998(void)
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
