/*
 * function: GIMMICK46_GetRotateAnim
 * address:  0x021F3BE8
 * packet:   pkt_ov046_021F3BE8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr push) between GIMMICK46_CalcUnitPose and GIMMICK46_ButtonEventProc.
 *
 * symbols:
 *   sGimmick46RotateAnimTable  0x021F41C4  data  a4
 */

extern int sGimmick46RotateAnimTable[][4];

int GIMMICK46_GetRotateAnim(int *p, int i)
{
    return sGimmick46RotateAnimTable[*p][i] - 5;
}
