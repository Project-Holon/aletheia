/*
 * function: FIELD_WFBC_DATA_LOCAL_IsPeopleListFull
 * address: 0x02186B08
 * packet: pkt_ov020_02186B08
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid 0x02161ECC thumb ov010
 */

extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(char *p);
int FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(char *p) { int i; for (i = 0; i < 10; i++) { if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(p + i * 24) == 0) return 0; } return 1; }
