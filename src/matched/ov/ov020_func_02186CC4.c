/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdSetFacingPersonParam
 * address:  0x02186CC4
 * packet:   pkt_ov020_02186CC4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl  0x02186090  thumb
 *   FIELD_WFBC_SetWordSetParentName  0x02193B68  thumb  ov021
 */

typedef short s16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetG3dMapper(unsigned char *p);
typedef unsigned char  u8;
extern void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(void *p);
extern void FIELD_WFBC_SetWordSetParentName(void *, void *, int, int, int);

int FIELD_WFBC_DATA_LOCAL_ScrCmdSetFacingPersonParam(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    int r5;
    int r4;
    s16 v[3];

    r6 = SCRCMD_WORK_GetScriptWork((void *)a1);
    s = (int *)SCRIPT_WORK_ResetFieldParam((int)r6);
    a = FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper((unsigned char *)s[1]));
    b = FIELDMAP_GetFieldPlayer((struct Obj00020 *)s[1]);
    c = FIELDMAP_GetMmdlSys((u8 *)s[1]);
    r6 = SCRIPT_WORK_GetWordSet(r6);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    r4 = SCRCMD_WORK_GetHeapId((void *)a1);
    FIELD_PLAYER_GetFrontGridPos((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    FIELD_WFBC_SetWordSetParentName(a, r6, FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos((u32)c, v[2], v[0], 0)), r5, r4);
    return 0;
}
