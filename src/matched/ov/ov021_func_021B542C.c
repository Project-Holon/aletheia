/*
 * function: SCRCMD_PROC_FLD_SetFieldRegionFromArchive
 * address:  0x021B542C
 * packet:   pkt_ov021_021B542C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   VM_GetU16  0x02011330  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 w[3]; } V12;
typedef struct { u32 w[6]; } V24;

typedef struct {
    u16 h0;
    u16 h2;
    u32 f4;
    V12 v8;
    V24 v14;
} Src;

typedef struct {
    u32 pad0[3];
    V12 v0c;
    u32 pad18[3];
    u16 h24;
    u16 h26;
    u32 f28;
    u32 pad2c;
    V24 v30;
} Out;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Stream;
extern void *FIELDMAP_GetCamera(void *p);
extern u16 VM_GetU16(struct Stream *s);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
extern void FIELD_CAMERA_StartMove(u8 *a, void *p, int n);

int SCRCMD_PROC_FLD_SetFieldRegionFromArchive(int a0, int a1)
{
    Src s;
    Out o;
    int r5;
    int r6;
    int r4;

    r5 = (int)FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)a1)));
    r6 = VM_GetU16((struct Stream *)a0);
    r4 = VM_GetU16((struct Stream *)a0);
    ARC_TOOL_ReadMember(&s, 0xa3, r6);
    o.h24 = s.h0;
    o.h26 = s.h2;
    o.f28 = s.f4;
    o.v0c = s.v8;
    o.v30 = s.v14;
    FIELD_CAMERA_StartMove((u8 *)r5, &o, r4);
    return 0;
}
