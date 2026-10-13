/*
 * function: EVENT_MAPCHANGE_AddWfbcMmdl
 * address:  0x02185928
 * packet:   pkt_ov020_02185928
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  byte-correct (MATCH*, 198 of 200 bytes, the rest is padding);
 *           the THM_CALL to ZONEDATA_IsZoneInTableDFC0 (arm9) has no witness: 0x02013DD0
 *           is an unlabelled arm9 leaf (the integrator's, inside ZONEDATA_IsZoneGroup118To120's
 *           listing extent; see unit_02013D9C.c's near-miss note). Verified
 *           C for it, per ov018_func_0217EC7C.c:
 *             int ZONEDATA_IsZoneInTableDFC0(int a0)
 *             { return ZONEDATA_IsZoneInTable(a0, d_0209DFC0, 4); }
 *
 * symbols:
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   GAME_DATA_GetMysteryRecvFlagA  0x020127E0  thumb
 *   func_020307B0  0x020307B0  arm
 *   FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders  0x02186538  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CountItemSlots  0x02186854  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders  0x021868B8  thumb  ov020
 *   FLDMMDL_AddMmdlHeaderList  0x0216CEAC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub02014444Obj;
int ZONEDATA_IsZoneInTableDFC0(int a0);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
u32 FIELD_STATUS_GetMapMode(struct Sub02014444Obj *o);
u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
u8 *GAME_DATA_GetSecondUnionInfo(void *p);
u8 *func_020127D0(u8 *o, u32 idx);
int GAME_DATA_GetMysteryRecvFlagA(int a);
u32 func_020307B0(void *p);
int FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(unsigned short *a, int b, int c);
int FIELD_WFBC_DATA_LOCAL_CountPeople(char *p, int which);
int FIELD_WFBC_DATA_LOCAL_CountItemSlots(u16 *p);
int FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(int a, int b, int c, int d);
void FLDMMDL_AddMmdlHeaderList(u32 a, u8 *p, u32 b, u32 n, u32 c);

void EVENT_MAPCHANGE_AddWfbcMmdl(void *a, const short *p)
{
    int r6;
    int r5;
    int r4;
    int ip;
    int sc;
    int s8;
    unsigned short *r7;

    if (ZONEDATA_IsZoneInTableDFC0((unsigned short)p[2]) == 0)
        return;

    r6 = (int)FIELD_STATUS_GetMapMode(GAME_DATA_GetMoveModelSys((const struct BigObj *)a));
    sc = (int)GAME_DATA_GetOccupyInfo((const struct BigObj *)a);
    s8 = (int)GAME_DATA_GetEventWork((const struct BigObj *)a);
    if (r6 == 0)
        r7 = (short unsigned int *)GAME_DATA_GetSecondUnionInfo(a);
    else
        r7 = (short unsigned int *)func_020127D0((u8 *)a, (int)0);

    r5 = FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(r7, r6, 1);
    ip = FIELD_WFBC_DATA_LOCAL_CountPeople((char *)r7, r6);
    if (r5 != 0 && ip != 0)
        FLDMMDL_AddMmdlHeaderList((int)sc, (u8 *)r5, (int)p[2], (int)ip, (int)s8);
    if (r5 != 0)
        func_020307B0((void *)r5);

    r5 = GAME_DATA_GetMysteryRecvFlagA((int)a);
    r4 = FIELD_WFBC_DATA_LOCAL_CountItemSlots((u16 *)r5);
    r5 = FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(r5, r6, r7[1], 1);
    if (r5 != 0 && r4 != 0)
        FLDMMDL_AddMmdlHeaderList((int)sc, (u8 *)r5, (int)p[2], (int)r4, (int)s8);
    if (r5 != 0)
        func_020307B0((void *)r5);
}
