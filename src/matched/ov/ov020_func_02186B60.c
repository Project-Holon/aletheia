/*
 * function: FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot
 * address: 0x02186B60
 * packet: pkt_ov020_02186B60
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid 0x02161ECC thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 pad; u16 ids[8]; } T;
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(T *p);
char *FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot(char *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((T *)(p + i * 24)) == 0)
            return p + i * 24;
    }
    return p;
}
