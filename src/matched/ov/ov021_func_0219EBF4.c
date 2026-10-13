/*
 * function: FLDMMDL_RAIL_WanderMoveBody
 * address:  0x0219EBF4
 * packet:   pkt_ov021_0219EBF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_RAIL_GetRandomTableEntry  0x0219EA10  thumb  ov021
 *   FLDMMDL_RAIL_GetRandomDirOfKind  0x0219EA24  thumb  ov021
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_RAIL_GetHitBitsDirNoAttr  0x0219E418  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb  ov021
 *   FLDMMDL_RAIL_CheckOutsideHomeArea  0x0219E9A8  thumb  ov021
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 *   FLDMMDL_RAIL_StoreNowLocation  0x0219EA78  thumb  ov021
 *   d_021D84AC     0x021D84AC  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

typedef struct {
    u8  pad[0xc];
    u8  state : 4;
    u8  hi : 4;
    s8  cnt;
    s8  e;
    u8  f;
} E;

extern u8 d_021D84AC[];

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern void FLDMMDL_OffMoveBitMoveEnd(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern u32 FLDMMDL_ACMD_Update(u8 *p);
extern int FLDMMDL_RAIL_GetRandomTableEntry(u32 *a, int b);
extern u32 FLDMMDL_RAIL_GetRandomDirOfKind(u32, u32);
extern void FLDMMDL_SetDirAll(u32, u16);
extern int FLDMMDL_RAIL_GetHitBitsDirNoAttr(u32, u16);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern int FLDMMDL_RAIL_GetLocationByDir(void *o, u32 k, void *buf);
extern int FLDMMDL_RAIL_CheckOutsideHomeArea(u32, u32, s32, u16 *);
extern void FLDMMDL_OnMoveBitMove(u32);
extern int FLDMMDL_RAIL_StoreNowLocation(E *, u32);

int FLDMMDL_RAIL_WanderMoveBody(u32 o)
{
    E *e;
    u32 k;
    u16 a[4];
    u16 b[4];

    e = FLDMMDL_GetMoveProcWork((void *)o);
    switch (e->state) {
    case 0:
        FLDMMDL_OffMoveBitMove((u8 *)o);
        FLDMMDL_OffMoveBitMoveEnd((u8 *)o);
        FLDMMDL_SetLocalAcmd((char *)o, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)((u32)FLDMMDL_GetDirDisp((void *)o)), (u32)0)));
        e->state++;
        break;
    case 1:
        if (!FLDMMDL_ACMD_Update((u8 *)o)) {
            break;
        }
        e->cnt = FLDMMDL_RAIL_GetRandomTableEntry((u32 *)d_021D84AC, -1);
        e->state++;
    case 2:
        e->cnt--;
        if (e->cnt != 0) {
            break;
        }
        e->state++;
    case 3:
        k = FLDMMDL_RAIL_GetRandomDirOfKind(e->hi, 9);
        FLDMMDL_SetDirAll(o, k);
        if (FLDMMDL_RAIL_GetHitBitsDirNoAttr(o, k)) {
            e->state = 0;
            break;
        }
        FLDMMDL_RAIL_GetNextLocation((void *)o, a);
        FLDMMDL_RAIL_GetLocationByDir((void *)o, (u16)k, b);
        if (a[0] != b[0]) {
            e->state = 0;
            break;
        }
        if (FLDMMDL_RAIL_CheckOutsideHomeArea(o, e->f, e->e, b)) {
            e->state = 0;
            break;
        }
        FLDMMDL_SetLocalAcmd((char *)o, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)k, (u32)0xc)));
        FLDMMDL_OnMoveBitMove(o);
        e->state++;
    case 4:
        if (FLDMMDL_ACMD_Update((u8 *)o)) {
            FLDMMDL_OffMoveBitMove((u8 *)o);
            e->state = 0;
        }
        break;
    }
    return FLDMMDL_RAIL_StoreNowLocation(e, o);
}
