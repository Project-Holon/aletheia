/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdGetFacingPersonMessageIndex
 * address:  0x02187000
 * packet:   pkt_ov020_02187000
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl  0x02186090  thumb
 *   FIELD_WFBC_GetCityType  0x0219391C  thumb  ov021
 */

typedef short s16;
typedef unsigned short u16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned int   u32;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetG3dMapper(unsigned char *p);
typedef unsigned char  u8;
extern void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(void *p);
extern unsigned char FIELD_WFBC_GetCityType(unsigned char *);

int FIELD_WFBC_DATA_LOCAL_ScrCmdGetFacingPersonMessageIndex(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    u16 *r4;
    int r5;
    int n;
    s16 v[3];

    r6 = SCRCMD_WORK_GetScriptWork((void *)a1);
    s = (int *)SCRIPT_WORK_ResetFieldParam((int)r6);
    a = FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper((unsigned char *)s[1]));
    b = FIELDMAP_GetFieldPlayer((struct Obj00020 *)s[1]);
    c = FIELDMAP_GetMmdlSys((u8 *)s[1]);
    SCRIPT_WORK_GetWordSet(r6);
    r4 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    FIELD_PLAYER_GetFrontGridPos((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    n = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos((u32)c, v[2], v[0], 0));
    r5 = (u16)(r5 - 1);
    if (FIELD_WFBC_GetCityType(a) == 0)
        *r4 = r5 + (n * 4 + 1);
    else
        *r4 = r5 + (n * 4 + 9);
    return 0;
}
