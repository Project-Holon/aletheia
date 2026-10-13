/*
 * function: FLDMMDL_RAIL_SearchMmdlByLocation
 * address:  0x0219E570
 * packet:   pkt_ov021_0219E570
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FIELD_RAIL_GetUnitScale  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_RAIL_GetNowLocation  0x0219E334  thumb  ov021
 *   FIELD_RAIL_IsPosNear  0x021B83B0  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern void FIELD_RAIL_GetLocationPos();
extern int FIELD_RAIL_GetUnitScale(u8 *o);
extern u32 func_0207C768(u32 a, u32 b);
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_RAIL_GetNowLocation(u32 a, u32 b);
extern int FIELD_RAIL_IsPosNear(const s32 *a, const s32 *b, s32 r);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);

u32 FLDMMDL_RAIL_SearchMmdlByLocation(u32 o, u32 k, u32 flag)
{
    u32 h;
    u32 m;
    u8 rec[12];
    u8 buf[12];
    u32 st;
    u32 cur;
    u8 tB[8];
    u8 tA[8];
    u32 lim;
    int z;

    st = 0;
    h = (u32)FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper((void *)o));
    FIELD_RAIL_GetLocationPos(h, k, rec);
    m = func_0207C768(FIELD_RAIL_GetUnitScale((u8 *)h), 0x4000);
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)o, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        z = (FLDMMDL_CheckStatusBit(cur, lim) == 0);
        if (!z) {
            if (flag) {
                FLDMMDL_RAIL_GetNowLocation(cur, (u32)tB);
                FIELD_RAIL_GetLocationPos(h, tB, buf);
                if (FIELD_RAIL_IsPosNear((const s32 *)rec, (const s32 *)buf, m)) {
                    return cur;
                }
            }
            FLDMMDL_RAIL_GetNextLocation((void *)cur, tA);
            FIELD_RAIL_GetLocationPos(h, tA, buf);
            if (FIELD_RAIL_IsPosNear((const s32 *)rec, (const s32 *)buf, m)) {
                return cur;
            }
        }
    }
    return 0;
}
