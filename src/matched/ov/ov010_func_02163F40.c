/*
 * function: FLDMMDL_MOVE_GetDirMapAttr
 * address:  0x02163F40
 * packet:   pkt_ov010_02163F40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb
 */

typedef unsigned int   u32;
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern void FLDMMDL_MOVE_GetMapAttr(int a, int *p, int *out);

int FLDMMDL_MOVE_GetDirMapAttr(int a, int dir)
{
    int buf[3];
    int v;

    v = -1;
    FLDMMDL_MOVE_GridToVectorPos(FLDMMDL_GetGridNowX((void *)a), FLDMMDL_GetGridNowZ((void *)a), buf);
    buf[1] = FLDMMDL_GetPosY((void *)a);
    FLDMMDL_MOVE_AddDirVector(dir, buf, 0x10000);
    FLDMMDL_MOVE_GetMapAttr(a, buf, &v);
    return v;
}
