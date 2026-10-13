/*
 * function: FIELD_WFBC_DATA_LOCAL_ClearPeopleList
 * address: 0x0218609C
 * packet: pkt_ov020_0218609C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry 0x02161E78 thumb ov010
 */
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(void *a0);
void FIELD_WFBC_DATA_LOCAL_ClearPeopleList(char *p) { int i; p += 8; for (i=0;i<10;i++) EVENT_FIELD_PROCLINK_ClearReturnEntry(p+i*0x18); }
