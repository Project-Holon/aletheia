/*
 * function: SCRCMD_PROC_FLD_StartCameraMoveFromStream
 * address:  0x021B53BC
 * packet:   pkt_ov021_021B53BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   VM_GetU16  0x02011330  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   FIELD_CAMERA_StartMove  0x0218F900  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 pad0[3];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 pad18[3];
    u16 h24;
    u16 h26;
    u32 f28;
    u32 pad2c;
    u32 w30[6];
} Out;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Stream;
extern void *FIELDMAP_GetCamera(void *p);
extern u16 VM_GetU16(struct Stream *s);
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void FIELD_CAMERA_StartMove(u8 *a, void *p, int n);

int SCRCMD_PROC_FLD_StartCameraMoveFromStream(struct Cursor *a0, int a1)
{
    Out o;
    int r4;

    r4 = (int)FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)a1)));
    o.h24 = VM_GetU16((struct Stream *)a0);
    o.h26 = VM_GetU16((struct Stream *)a0);
    o.f28 = VM_GetU32(a0);
    o.f0c = VM_GetU32(a0);
    o.f10 = VM_GetU32(a0);
    o.f14 = VM_GetU32(a0);
    o.w30[0] = 0;
    o.w30[1] = 1;
    o.w30[2] = 1;
    o.w30[3] = 1;
    o.w30[4] = 0;
    o.w30[5] = 1;
    FIELD_CAMERA_StartMove((u8 *)r4, &o, VM_GetU16((struct Stream *)a0));
    return 0;
}
