/*
 * function: FLDMMDL_RAIL_CheckHitMmdl
 * address:  0x0219E498
 * packet:   pkt_ov021_0219E498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FIELD_RAIL_GetUnitScale  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_IsMoving  0x021B8040  thumb  ov021
 *   FIELD_RAIL_WORK_GetLastKey  0x021B8038  thumb  ov021
 *   FIELD_RAIL_WORK_QueryStep  0x021B7E60  thumb  ov021
 *   FIELD_RAIL_WORK_GetPrevPos  0x021B7ED4  thumb  ov021
 *   FIELD_RAIL_IsPosNear  0x021B83B0  thumb  ov021
 * Addresses are Black-image addresses.
 * EXACT* is the 2-byte alignment pad after the last pop.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern void FIELD_RAIL_GetLocationPos();
extern int FIELD_RAIL_GetUnitScale(u8 *o);
extern u32 func_0207C768(u32 a, u32 b);
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern u8 FIELD_RAIL_WORK_IsMoving(u8 *p);
extern u8 FIELD_RAIL_WORK_GetLastKey(u8 *p);
extern void FIELD_RAIL_WORK_QueryStep();
extern void FIELD_RAIL_WORK_GetPrevPos();
extern int FIELD_RAIL_IsPosNear(const s32 *a, const s32 *b, s32 r);

int FLDMMDL_RAIL_CheckHitMmdl(u32 o, u32 k)
{
    u32 t;
    u32 h;
    u32 m;
    u8 rec[12];
    u8 tA[12];
    u32 cur;
    u32 st;
    u32 lim;
    u32 s;
    int z;

    s = (u32)FLDMMDL_GetMmdlSys((void *)o);
    h = (u32)FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper((void *)s));
    st = 0;
    FIELD_RAIL_GetLocationPos(h, k, rec);
    m = func_0207C768(FIELD_RAIL_GetUnitScale((u8 *)h), 0x4000);
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)s, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        if (cur == o) {
            continue;
        }
        if (FLDMMDL_CheckStatusBit(cur, 0x80) != 0) {
            continue;
        }
        z = (FLDMMDL_CheckStatusBit(cur, lim) == 0);
        if (!z) {
            t = (u32)FLDMMDL_RAIL_GetRailWork((void *)cur);
            if (FIELD_RAIL_WORK_IsMoving((u8 *)t)) {
                FIELD_RAIL_WORK_QueryStep(t, FIELD_RAIL_WORK_GetLastKey((u8 *)t), 0, tA);
                if (FIELD_RAIL_IsPosNear((const s32 *)rec, (const s32 *)tA, m)) {
                    return 1;
                }
            }
            FIELD_RAIL_WORK_GetPrevPos(t, tA);
            if (FIELD_RAIL_IsPosNear((const s32 *)rec, (const s32 *)tA, m)) {
                return 1;
            }
        }
    }
    return 0;
}
