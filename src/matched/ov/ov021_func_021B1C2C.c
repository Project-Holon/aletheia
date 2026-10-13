/*
 * function: SCRCMD_FLDMMDL_SearchMmdlAtGrid
 * address:  0x021B1C2C
 * packet:   pkt_ov021_021B1C2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 */

typedef signed short s16;

void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
int SCRIPT_WORK_ResetFieldParam(int a0);
s16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
void *FIELDMAP_GetMmdlSys(unsigned char *p);
typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
u8 *FLDMMDL_SysSearchGridPosHeight(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
u16 FLDMMDL_GetObjId(void *p);

int SCRCMD_FLDMMDL_SearchMmdlAtGrid(int a, int b)
{
    int r7;
    s16 *s8;
    s16 *r6;
    int sc;
    int s10;
    int r4;
    int r0;

    r7 = ((int *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1];
    s8 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r6 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    sc = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    s10 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r0 = (int)FLDMMDL_SysSearchGridPosHeight((u32)FIELDMAP_GetMmdlSys((void *)r7), (s16)sc, (s16)r4, s10 << 16, 0x8000, (int)0);
    if (r0) {
        *r6 = 1;
        *s8 = FLDMMDL_GetObjId((void *)r0);
    } else {
        *r6 = 0;
    }
    return 0;
}
