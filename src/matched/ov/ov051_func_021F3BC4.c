/*
 * function: FIELD_GIMMICK_D06_ScanSlide
 * address:  0x021F3BC4
 * packet:   pkt_ov051_021F3BC4
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * q[3] is padding (four bytes of frame the original carries above q[1]);
 * m[1] keeps the mask in memory (a plain int folds); d as u16 puts the
 * parameter spill first.
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 *   FLDMMDL_MOVE_AddDirGrid  0x02164240  thumb
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   func_021AB3F8  0x021AB3F8  thumb
 */

extern int FIELDMAP_GetG3dMapper(int a);
extern int FLDMMDL_GetGridNowX(int a);
extern int FLDMMDL_GetGridNowY(int a);
extern int FLDMMDL_GetGridNowZ(int a);
extern void FLDMMDL_MOVE_AddDirGrid(int a, short *b, short *c, int d);
extern int FLDMMDL_MOVE_HitCheckMoveCurrent(int a, int b, int c, int d, int e);
extern void FLDMMDL_MOVE_GridToVectorPos(int a, int b, int *c);
extern int FLDMMDL_GetPosY(int a);
extern int MAP_ATTR_GetAt(int a, int *b);
extern int MAP_ATTR_GetTerrainId(int a);
extern int func_021AB3F8(int a);

int FIELD_GIMMICK_D06_ScanSlide(int *a, int *bp, int c, unsigned short d, unsigned int *out)
{
    int r7 = *bp;
    unsigned short i = 0;
    int q[3];
    short pt[2];
    int m[1];
    int found = 0;
    int sp0c;
    int sp8;
    int r;

    sp0c = FIELDMAP_GetG3dMapper(a[2]);
    pt[1] = FLDMMDL_GetGridNowX(r7);
    sp8 = FLDMMDL_GetGridNowY(r7);
    pt[0] = FLDMMDL_GetGridNowZ(r7);
    m[0] = 1;
    do {
        FLDMMDL_MOVE_AddDirGrid(c, &pt[1], &pt[0], 1);
        r = FLDMMDL_MOVE_HitCheckMoveCurrent(r7, pt[1], sp8, pt[0], c) & ~m[0];
        if (r != 0) {
            if (r & 2) {
                FLDMMDL_MOVE_GridToVectorPos(pt[1], pt[0], &q[0]);
                q[1] = FLDMMDL_GetPosY(r7);
                r = MAP_ATTR_GetAt(sp0c, q);
                if (r != -1) {
                    if (func_021AB3F8(MAP_ATTR_GetTerrainId(r)) == 1)
                        found = 1;
                }
            }
            break;
        }
        i = i + 1;
    } while (i < d);
    if (found == 0)
        i = 0;
    *out = i;
    return found;
}
