/*
 * file:     unit_02070C24.c
 * function: NNSi_G3dAnmCalcNsBva
 * address:  0x02070C24
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bit `n` of a bitmap, written out through the caller's pointer. `n` is
 *  * (s->f0 >> 12) * b->h6 + idx -- the shift of f0 is the *arithmetic* form
 *  * (`asr ip, r3, #0xc`, so f0 is signed) while the shift of the summed index
 *  * is the *logical* one (`lsr r1, r2, #5`), which is the whole difference:
 *  * the local holding n has to be unsigned while the field it is built from
 *  * stays signed, and making the local signed too is one byte wrong.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* NNSG3dResVisAnm: only the node count is read. */
struct VisAnm { u8 unused00[6]; u16 numNode; };
/* NNSG3dAnmObj: current frame (fx32), blend ratio, animation resource. */
struct AnmObj { int frame; u32 ratio; struct VisAnm *pResAnm; };

/* NNSi_G3dAnmCalcNsBva shape: read the visibility bit of node nodeIdx at the current frame. */
void NNSi_G3dAnmCalcNsBva(u32 *pResult, struct AnmObj *pAnmObj, int nodeIdx)
{
    struct VisAnm *pResAnm = pAnmObj->pResAnm;
    u32 bitIdx = (pAnmObj->frame >> 12) * pResAnm->numNode + nodeIdx;

    *pResult = *(u32 *)((u8 *)pResAnm + ((bitIdx >> 5) * 4) + 0xc) & (1u << (bitIdx & 0x1f));
}
