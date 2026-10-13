/*
 * function: FLDMMDL_MOVECODE_BackForthStepFaceDir
 * address:  0x0219A8C0
 * packet:   pkt_ov021_0219A8C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDirHeader  0x0216D5D4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_SetDirMove  0x0216D600  thumb  ov010
 *   FLDMMDL_MOVECODE_IsMirrorEventType  0x0219B358  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FLDMMDL_GetDirHeader(void *p);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);
extern int FLDMMDL_SetDirMove(int a0, u16 a1);
extern int FLDMMDL_MOVECODE_IsMirrorEventType(u32);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);

int FLDMMDL_MOVECODE_BackForthStepFaceDir(u32 a, u8 *b)
{
    u32 cur = FLDMMDL_GetDirHeader((void *)a);
    if (b[1] == 1)
        cur = FLDMMDL_MOVE_GetDirTableValue((u16)cur);
    FLDMMDL_SetDirMove(a, cur);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(a) == 0)
        FLDMMDL_SetDirDispCheckPause((u32)a, (u16)cur);
    b[0] = 1;
    return 1;
}
