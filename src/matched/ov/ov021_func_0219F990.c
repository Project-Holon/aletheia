/*
 * function: FLDMMDL_DRAW_UpdateWalkOffset
 * address:  0x0219F990
 * packet:   pkt_ov021_0219F990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_ACMD_CheckAnimePaused  0x02197C9C  thumb  ov021
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_IsFieldPlayerCreated  0x02188CBC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetStepKind  0x021A3080  thumb  ov021
 *   FLDMMDL_DRAW_CheckStepFrame  0x0219FADC  thumb  ov021
 *   FLDMMDL_DRAW_ShiftOffsetByDir  0x0219FAB4  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   func_02013D9C  0x02013D9C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec;

extern void *FLDMMDL_GetObjCodeParam(void *p);
extern s32 FLDMMDL_ACMD_CheckAnimePaused(u32);
extern void FLDMMDL_GetDrawOffset(u8 *p, u8 *q);
extern int FLDMMDL_GetGridNowX(void *p);
extern u16 FLDMMDL_GetZoneId(void *p);
extern u16 FLDMMDL_GetObjId(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetFieldMap(void *p);
extern int FIELDMAP_IsFieldPlayerCreated(u32);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELD_PLAYER_GetStepKind(u8 *p);
extern int FLDMMDL_DRAW_CheckStepFrame(u8 *p, int a, u8 *q);
extern void FLDMMDL_DRAW_ShiftOffsetByDir(u32 a, u32 b, u8 *c, int *d);
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern u32 func_02013D9C(u32 id);

void FLDMMDL_DRAW_UpdateWalkOffset(u32 a, u8 *p, u8 b)
{
    Vec d;
    Vec v;
    u32 u;
    s32 s14;
    u32 s10;
    s32 sc;
    u8 *info;
    int clr;
    int ok;
    int ff;
    u32 t;
    u8 m;
    void *x;

    ok = 1;
    info = FLDMMDL_GetObjCodeParam((void *)a);
    ff = 0;
    d.x = 0;
    d.y = 0;
    d.z = 0;
    s14 = FLDMMDL_ACMD_CheckAnimePaused(a);
    FLDMMDL_GetDrawOffset((u8 *)a, (u8 *)(&v));
    sc = FLDMMDL_GetGridNowX((void *)a);
    s10 = FLDMMDL_GetZoneId((void *)a);
    t = FLDMMDL_GetObjId((void *)a);
    if (t == 0xff)
        ff = ok;
    clr = (t == 0xfc) ? 1 : 0;
    if (ff != 0) {
        u = FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys((void *)a));
        if (FIELDMAP_IsFieldPlayerCreated(u) != 0 && (x = FIELDMAP_GetFieldPlayer((void *)u)) != 0) {
            ok = FIELD_PLAYER_GetStepKind(x) != 0;
        }
    }
    if (s14 != 0 || (v.y > 0x1800 && info[3] != 11)) {
        d.y = v.y;
    } else if (FLDMMDL_DRAW_CheckStepFrame(p, b, info) == 0 && ok != 0) {
        d.y = d.y + 0x1800;
    }
    if (func_02013D9C(s10) != 0 && ff == 0) {
        m = sc % 3;
        if (m == 0)
            d.z = d.z - 0x219a;
        else if (m == 2)
            d.z = d.z + 0x219a;
        d.z = d.z - 0x2000;
    }
    FLDMMDL_DRAW_ShiftOffsetByDir(a, b, info, (int *)(&d));
    if (clr) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
    }
    FLDMMDL_SetDrawOffset(a, &d);
    p[3]++;
}
