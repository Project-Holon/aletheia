/*
 * function: FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId
 * address: 0x02186A2C
 * packet: pkt_ov020_02186A2C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_IsNpcPresent 0x02186A58 thumb ov020
 */

extern int FIELD_WFBC_DATA_LOCAL_IsNpcPresent(char *p, int id);
int FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(char *p, int id) { int i; int n; n = 0; for (i = 0; i < 30; i++) { if (FIELD_WFBC_DATA_LOCAL_IsNpcPresent(p, i) == 0) { if (n == id) return i; n++; } } return 0; }
