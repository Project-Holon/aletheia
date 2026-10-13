/*
 * function: EVENT_FIELD_PROCLINK_ApplyReturnEntry
 * address:  0x02161F90
 * packet:   pkt_ov010_02161F90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_GetEventdataEntry  0x02161DC4  thumb
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb
 *   FIELD_WFBC_DATA_LOCAL_InsertPersonForCity  0x02186520  thumb
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry  0x02161E78  thumb
 *   EVENT_FIELD_PROCLINK_CompactReturnList  0x02161E60  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *EVENT_FIELD_PROCLINK_GetEventdataEntry(char *, int, int);
extern int *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int a, int id);
extern u16 *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(int h);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(int);
extern void FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(u16 *, int, u8 *);
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(void *a0);
extern int EVENT_FIELD_PROCLINK_CompactReturnList(int a0, int a1);

void EVENT_FIELD_PROCLINK_ApplyReturnEntry(int unused, u16 *x, char *y, int z, u16 w, u16 v)
{
    u8 *r4;
    int h;
    u16 *q;

    r4 = EVENT_FIELD_PROCLINK_GetEventdataEntry(y, w, 1);
    h = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(w, v);
    q = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(h);
    if (x[1] == 0)
        r4[2] = q[3];
    else
        r4[2] = q[2];
    r4[3] = 7;
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(h);
    FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(x, z, r4);
    EVENT_FIELD_PROCLINK_ClearReturnEntry(r4);
    EVENT_FIELD_PROCLINK_CompactReturnList((int)y, 1);
}
