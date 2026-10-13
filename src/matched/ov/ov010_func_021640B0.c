/*
 * function: FLDMMDL_MOVE_UpdateMapAttr
 * address:  0x021640B0
 * packet:   pkt_ov010_021640B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb
 *   FLDMMDL_GetGridOldY  0x0216D810  thumb
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb
 *   FLDMMDL_SetOldAttr  0x0216D7E0  thumb
 *   FLDMMDL_SetNowAttr  0x0216D7D8  thumb
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb
 */

typedef short s16;

typedef unsigned int   u32;
extern int FLDMMDL_CheckStatusBitAttrGetOff(void *a0);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldY(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern int FLDMMDL_MOVE_GetMapAttr(int a, int *p, int *out);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern void FLDMMDL_SetOldAttr(void *p, u32 v);
extern void FLDMMDL_SetNowAttr(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

int FLDMMDL_MOVE_UpdateMapAttr(int a)
{
    int rect[3];
    int o1;
    int o2;
    int r1;
    int r2;

    r1 = 0;
    r2 = 0;
    o1 = -1;
    o2 = -1;
    if (FLDMMDL_CheckStatusBitAttrGetOff((void *)a) == 0) {
        int x = FLDMMDL_GetGridOldX((void *)a);
        int y = FLDMMDL_GetGridOldY((void *)a);
        int z = FLDMMDL_GetGridOldZ((void *)a);
        rect[0] = x << 16;
        rect[1] = y << 16;
        rect[2] = z << 16;
        r1 = FLDMMDL_MOVE_GetMapAttr(a, rect, &o1);
        FLDMMDL_MOVE_GridToVectorPos((s16)FLDMMDL_GetGridNowX((void *)a), (s16)FLDMMDL_GetGridNowZ((void *)a), rect);
        rect[1] = FLDMMDL_GetPosY((void *)a);
        r2 = FLDMMDL_MOVE_GetMapAttr(a, rect, &o2);
    }
    if (r1 == 1)
        FLDMMDL_SetOldAttr((void *)a, o1);
    if (r2 == 1)
        FLDMMDL_SetNowAttr((void *)a, o2);
    if (r2 == 1) {
        FLDMMDL_ClearMoveBit((char *)a, 0x800);
        return 1;
    }
    FLDMMDL_SetMoveBit((void *)a, 0x800);
    return 0;
}
