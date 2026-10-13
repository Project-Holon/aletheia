/*
 * function: FLDMMDL_RAIL_ShuttleMoveBody
 * address:  0x0219EDC4
 * packet:   pkt_ov021_0219EDC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_GetDirHeader  0x0216D5D4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_RAIL_GetHitBitsDirNoAttr  0x0219E418  thumb  ov021
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb  ov021
 *   FLDMMDL_RAIL_CheckOutsideHomeArea  0x0219E9A8  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_RAIL_StoreNowLocation  0x0219EA78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
} T;

typedef struct {
    u8  pad[0xc];
    u8  state;
    u8  d;
    s8  e;
    u8  f;
} E;

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int FLDMMDL_GetDirHeader(void *p);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);
extern int FLDMMDL_SetDirAll(int a0, int a1);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern u16 FLDMMDL_GetDirMove(void *p);
extern int FLDMMDL_RAIL_GetHitBitsDirNoAttr(u32 a, u32 b);
extern void FLDMMDL_RAIL_GetLocationByDir(u32, u16, T *);
extern int FLDMMDL_RAIL_CheckOutsideHomeArea(u32, u32, s32, T *);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern void FLDMMDL_OnMoveBitMove(u32);
extern u32 FLDMMDL_ACMD_Update(u8 *p);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern int FLDMMDL_RAIL_StoreNowLocation(E *, u32);

int FLDMMDL_RAIL_ShuttleMoveBody(u32 o)
{
    E *e;
    u32 s;
    u32 k;
    u32 z;
    int r;
    T c;
    T b;

    e = FLDMMDL_GetMoveProcWork((void *)o);
    switch (e->state) {
    case 0:
        k = FLDMMDL_GetDirHeader((void *)o);
        if (e->d == 1) {
            k = (u32)FLDMMDL_MOVE_GetDirTableValue((u16)k);
        }
        FLDMMDL_SetDirAll((u32)o, (u16)k);
        e->state = 1;
    case 1:
        FLDMMDL_RAIL_GetNextLocation((void *)o, &c);
        if (e->d != 0 && e->f == c.d && e->e == c.c) {
            FLDMMDL_SetDirAll((u32)o, (u16)((u32)FLDMMDL_MOVE_GetDirTableValue((u16)FLDMMDL_GetDirMove((void *)o))));
            e->d = 0;
        }
        z = 0;
        k = FLDMMDL_GetDirMove((void *)o);
        s = (u32)FLDMMDL_RAIL_GetHitBitsDirNoAttr(o, (u16)k);
        FLDMMDL_RAIL_GetLocationByDir(o, k, &b);
        r = FLDMMDL_RAIL_CheckOutsideHomeArea(o, e->f, e->e, &b);
        if (c.a != b.a) {
            z = 1;
        }
        if ((s & 1) || r || z) {
            e->d = 1;
            k = (u32)FLDMMDL_MOVE_GetDirTableValue((u16)k);
            s = (u32)FLDMMDL_RAIL_GetHitBitsDirNoAttr(o, (u16)k);
            FLDMMDL_RAIL_GetLocationByDir(o, k, &b);
        }
        FLDMMDL_SetLocalAcmd((char *)o, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)k, (u16)(s == 0 ? 0xc : 0x20))));
        FLDMMDL_OnMoveBitMove(o);
        e->state = 2;
        break;
    case 2:
        if (FLDMMDL_ACMD_Update((u8 *)o) == 1) {
            FLDMMDL_OffMoveBitMove((u8 *)o);
            e->state = 0;
        }
        break;
    }
    return FLDMMDL_RAIL_StoreNowLocation(e, o);
}
