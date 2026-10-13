/*
 * function: FLDMMDL_DRAW_DrawBillboardOffset
 * address:  0x0219F634
 * packet:   pkt_ov021_0219F634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_DRAW_GetDirIndex  0x0219FFD4  thumb  ov021
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_DRAW_AddHeightOffset  0x0219FFBC  thumb  ov021
 *   BILLBOARD_ACT_GetEntryList  0x02050848  arm
 *   BILLBOARD_ACT_GetEntryCursor  0x02050880  arm
 *   FLDMMDL_DRAW_GetFrameOffsetZero  0x0219F628  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   FLDMMDL_DRAW_RotateByCamera  0x0219F5D4  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   gMmdlDrawBillboardShift     0x021D854C  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec;

typedef struct {
    u16 id;
    u8  b2;
    u8  b3;
    u8  b4;
    u8  b5;
} E;

extern const Vec gMmdlDrawBillboardShift;

struct Trip;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u32 FLDMMDL_DRAW_GetDirIndex(u32);
extern u16 FLDMMDL_GetDrawStatus(void *p);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_AddHeightOffset(u32 a, u32 *p);
extern u16 BILLBOARD_ACT_GetEntryList(u8 *p, int i);
extern u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i);
extern int FLDMMDL_DRAW_GetFrameOffsetZero(u32 a, u32 b, u32 c, u32 d);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetFieldMap(void *p);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void FLDMMDL_DRAW_RotateByCamera(u32 a, s32 *b, s32 *c);
extern void func_0207C9D0(Vec *, Vec *, Vec *);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);

void FLDMMDL_DRAW_DrawBillboardOffset(u32 o)
{
    E *e;
    u32 h;
    u32 a;
    u32 b;
    u16 c;
    Vec pos;
    Vec d;
    Vec tmp;
    u32 flag;
    u32 x;

    flag = 0;
    e = FLDMMDL_GetDrawProcWork((void *)o);
    if (e->id == 0xFFFF) {
        return;
    }
    h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(o));
    a = FLDMMDL_DRAW_GetDirIndex(o);
    b = FLDMMDL_GetDrawStatus((void *)o);
    c = a + b * 4;
    if (a != e->b4 || e->b5 != b) {
        e->b4 = a;
        flag = 1;
        e->b5 = b;
        BILLBOARD_ACT_SetEntryList((void *)h, e->id, c);
        BILLBOARD_ACT_SetEntryCursor((void *)h, e->id, 0);
    }
    FLDMMDL_DRAW_UpdateBlactFlags(o, h, e->id, flag, 1);
    FLDMMDL_ACMD_GetDrawPos((u8 *)o, (s32 *)(&pos));
    FLDMMDL_DRAW_AddHeightOffset(o, (u32 *)(&pos));
    x = BILLBOARD_ACT_GetEntryList((u8 *)h, e->id);
    FLDMMDL_DRAW_GetFrameOffsetZero(o, x, BILLBOARD_ACT_GetEntryCursor((u8 *)h, e->id), (u32)(&d));
    pos.x += d.x;
    pos.y += d.y;
    pos.z += d.z;
    if (e->b2 == 0) {
        tmp = gMmdlDrawBillboardShift;
        FLDMMDL_DRAW_RotateByCamera(FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera((void *)FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys((void *)o)))), (s32 *)(&tmp), (s32 *)(&tmp));
        func_0207C9D0(&pos, &tmp, &pos);
    } else {
        pos.y -= 0xC000;
        pos.z += 0x8000;
    }
    BILLBOARD_SetElemPos((u8 *)BILLBOARD_ACT_GetBoard((u32 *)h), e->id, (struct Trip *)(&pos));
}
