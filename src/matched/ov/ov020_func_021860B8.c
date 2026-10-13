/*
 * function: FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList
 * address: 0x021860B8
 * packet: pkt_ov020_021860B8
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
void FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList(char *p) { int i; p += 0xf8; for (i=0;i<10;i++) EVENT_FIELD_PROCLINK_ClearReturnEntry(p+i*0x18); }
