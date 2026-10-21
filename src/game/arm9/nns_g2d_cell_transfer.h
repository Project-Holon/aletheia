#ifndef GAME_ARM9_NNS_G2D_CELL_TRANSFER_H
#define GAME_ARM9_NNS_G2D_CELL_TRANSFER_H

#include "../types.h"

/* Cell graphics transfer state. */

typedef enum {
    VRAM_TYPE_3DMAIN = 0,
    VRAM_TYPE_2DMAIN,
    VRAM_TYPE_2DSUB,
    VRAM_TYPE_MAX
} VRamType;

typedef struct {
    u32 baseAddrOfVram[VRAM_TYPE_MAX];
} VRamLocation;

typedef struct CellTransferState {
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

CellTransferState *NNSi_G2dGetCellTransferState(u32 stateIdx);
void NNS_G2dInitCellTransferStateManager(CellTransferState *pStates, u32 numStates, TransferFunc pTransferFunc);
void NNS_G2dSetCellTransferState(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void NNS_G2dUpdateCellTransferStateManager(void);
CellTransferState *NNSi_G2dRequestCellTransferState(u32 stateIdx, u32 srcOffset, u32 szByte);
int NNSi_G2dGetCellTransferStateIndex(void);
void NNSi_G2dResetCellTransferState(u32 stateIdx);

#endif
