/*
 * file:     unit_0206A9DC.c
 * function: func_0206A9DC
 * address:  0x0206A9DC
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *
 * The sibling of src/matched/func_0206AA0C.c, one slot lower in the same rig
 * register block: copies the caller's three-word record into the block at
 * 0x02148C2C (= g_02148B4C + 0xE0) and clears the 0xa4 bit trio of the
 * "initialised subsystems" flag word at g_02148B4C + 0xFC.
 *
 * As in func_0206AA0C, the destination is spelled as one object WITH the flag
 * word rather than as a separate extern: that is what orders every access
 * behind the 12-byte ldm/stm copy and keeps the leaf at the original 48 bytes
 * with `ldr r3/r0, [pc]` twice.  Both pool words resolve on `literal` (x115).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A9DC.c \
 *       --func func_0206A9DC --addr 0x0206A9DC --cc 1.1p1 --arm
 */
#include "unit_0206A110_types.h"

/* NNS_G3dGlbBaseTrans: set the base translation of the model matrix. */
void func_0206A9DC(const VecFx32 *pTrans)
{
    if (pTrans == 0) {
        return;
    }
    NNS_G3dGlb.prmBaseTrans = *pTrans;
    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_BASE_DEPENDENT;
}
