/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdMarkFacingPerson
 * address:  0x02186BE4
 * packet:   pkt_ov020_02186BE4
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
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl  0x02186090  thumb
 *   FIELD_WFBC_ApplyGiftMood  0x02193B40  thumb  ov021
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 */

typedef short s16;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetG3dMapper(unsigned char *p);
typedef unsigned char  u8;
extern void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(void *p);
struct V;
extern void FIELD_WFBC_ApplyGiftMood(struct V *v, u32 key);

int FIELD_WFBC_DATA_LOCAL_ScrCmdMarkFacingPerson(int a0, int a1)
{
    int *s;
    void *a;
    void *c;
    void *d;
    int e;
    s16 v[3];

    s = (int *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)a1));
    a = FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper((unsigned char *)s[1]));
    c = FIELDMAP_GetFieldPlayer((struct Obj00020 *)s[1]);
    d = FIELDMAP_GetMmdlSys((u8 *)s[1]);
    FIELD_PLAYER_GetFrontGridPos((u32)c, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    e = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(FLDMMDL_SysSearchGridPos((u32)d, v[2], v[0], 0));
    FIELD_WFBC_ApplyGiftMood(a, e);
    return 0;
}
